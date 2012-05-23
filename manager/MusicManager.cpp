#include "MusicManager.h"

MusicManager *MusicManager::s_musicMgr = NULL;

MusicManager::MusicManager(QObject *parent)
    : QObject(parent)
{
    m_AudioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    m_Media = new Phonon::MediaObject(this);
    Phonon::createPath(m_Media, m_AudioOutput);
    m_Media->setTickInterval(1000);

    connect(m_Media, SIGNAL(tick(qint64)), this, SLOT(timeChangedSlot(qint64)));
    connect(m_Media,SIGNAL(currentSourceChanged(Phonon::MediaSource)), this, SLOT(currentSourceChangedSlot(Phonon::MediaSource)));
    connect(m_Media, SIGNAL(totalTimeChanged(qint64)), this, SLOT(MusicDurationSlot(qint64)));
}

MusicManager* MusicManager::getInstance()
{
    if(NULL == s_musicMgr)
    {
        s_musicMgr = new MusicManager;
    }
    return s_musicMgr;
}

void MusicManager::deleteInstance()
{
    if(NULL != s_musicMgr)
    {
        delete s_musicMgr;
        s_musicMgr = NULL;
    }
}

QString MusicManager::getMusicPath()
{
    return m_currentMusicPath;
}


void MusicManager::setMusicPath(QString path)
{
    m_currentMusicPath = path;
    m_Media->setCurrentSource(m_currentMusicPath);
}

void MusicManager::Play()
{
    m_Media->play();
}

void MusicManager::Pause()
{
    if(m_Media != NULL)
        m_Media->pause();
}

void MusicManager::Stop()
{
    if(m_Media != NULL)
        m_Media->stop();
}

void MusicManager::timeChangedSlot(qint64 timeElapsed)
{
    m_time = timeElapsed / 1000;
    m_currentMinElapsed = m_time / 60;
    m_currentSecElapsed = m_time % 60;
    QString minute = "";
    QString seconde = "";
    QString time = "";
    minute = QString::number(m_currentMinElapsed);
    seconde = QString::number(m_currentSecElapsed);
    if(m_currentSecElapsed < 10)
        seconde = "0" + seconde;
    time = minute + ":" + seconde;

    emit timeChanged(m_time);
    emit timeChanged(time);
}

void MusicManager::currentSourceChangedSlot(Phonon::MediaSource mediasource)
{
    emit currentSourceChanged(mediasource.fileName());
}

void MusicManager::changeVolume(int volume)
{
    qreal newVolume = volume;
    newVolume /= 100;
    m_AudioOutput->setVolume(newVolume);
}

void MusicManager::MusicDurationSlot(qint64 newTotalTime)
{
    newTotalTime /= 1000;
    m_currentDurationInSeconde = newTotalTime;
    m_currentMinTotal = newTotalTime / 60;
    m_currentSecTotal = newTotalTime % 60;
    emit totalTimeChanged();
}


void MusicManager::getTotalMusicDuration(int *minute, int *seconde)
{
    *minute = m_currentMinTotal;
    *seconde = m_currentSecTotal;
}

void MusicManager::getTotalMusicDuration(qint64 *duration)
{
    *duration = m_currentDurationInSeconde;
}

void MusicManager::getTotalMusicDuration(QString *duration)
{

    QString qstr_seconde = "";
    if(m_currentSecTotal < 10)
        qstr_seconde = "0" + QString::number(m_currentSecTotal);
    else
        qstr_seconde = QString::number(m_currentSecTotal);

    *duration = QString::number(m_currentMinTotal) + ":" + qstr_seconde;
}

qint64 MusicManager::getTimeElapsed()
{
    return m_time;
}

void MusicManager::changePositionMusic(int newTime)
{
    m_Media->seek(newTime * 1000);
}
