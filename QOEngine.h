/*!
 * \copyright (c) Nokia Corporation and/or its subsidiary(-ies) (qt-info@nokia.com) and/or contributors
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * \license{This source file is part of QmlOgre abd subject to the BSD license that is bundled
 * with this source code in the file LICENSE.}
 */

#ifndef QOEngineITEM_H
#define QOEngineITEM_H

#include "QOgreGlobal.h"
#include <QObject>
#include <QQuickWindow>
#include <QOpenGLContext>
#include <OgreString.h>

namespace Ogre
{
class Root;
class RenderTexture;
class Viewport;
class RenderTarget;
class RenderWindow;
}

/**
 * @brief The QOEngineItem class
 * Must only be constructed from within Qt QML rendering thread.
 */
class DLL_EXPORT QOEngine : public QObject
{
    Q_OBJECT

public:
    QOEngine(QQuickWindow* window = 0);
    ~QOEngine();

    Ogre::Root* getRoot();
    Ogre::RenderWindow* getRenderWindow();
    QQuickWindow* getQQuickWindow();
    bool isStarted() const;
    void startEngine();
    void stopEngine();

    void activateOgreContext();
    void doneOgreContext();

    QOpenGLContext* ogreContext() const;

    QSGTexture* createTextureFromId(uint id,
                                    const QSize& size,
                                    QQuickWindow::CreateTextureOptions options
                                        = QQuickWindow::CreateTextureOption(0)) const;

    void setupResources(void);

private:
    Ogre::String mResourceConfig;
    Ogre::RenderWindow* mOgreWindow;
    Ogre::Root* mRoot;
    QQuickWindow* mQuickWindow;
    QOpenGLContext* mOgreContext;
protected:
    void setQuickWindow(QQuickWindow* window);
};

#endif // QOEngineITEM_H
