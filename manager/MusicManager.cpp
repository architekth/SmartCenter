#include "MusicManager.h"

MusicManager *MusicManager::s_musicMgr = NULL;

MusicManager::MusicManager(QObject *parent)
    : QObject(parent)
{
    m_AudioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
    m_Media = new Phonon::MediaObject(this);
    Phonon::createPath(m_Media, m_AudioOutput);
    m_Media->setTickInterval(1000);

    connect(m_Media, SIGNAL(tick(qint64)), this, SLOT(timeChanged(qint64)));
    connect(m_Media,SIGNAL(currentSourceChanged(Phonon::MediaSource)), this, SLOT(currentSourceChangedSlot(Phonon::MediaSource)));
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

void MusicManager::Play(QString path)
{
    setMusicPath(path);
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

void MusicManager::timeChanged(qint64 timeElapsed)
{
    m_time = timeElapsed;
}

void MusicManager::currentSourceChangedSlot(Phonon::MediaSource mediasource)
{
    emit currentSourceChanged(mediasource.fileName());
}
