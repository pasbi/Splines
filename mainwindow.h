#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "scene.h"
#include "viewport.h"
#include "Objects/spline.h"
#include <QActionGroup>
#include "Managers/manager.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setScene(Scene* scene);


public slots:
    bool save();
    bool saveAs();
    bool load();
    bool newScene();

private:
    bool _isSaved;
    bool canDiscard();

protected:
    void closeEvent(QCloseEvent *e);

private:
    Ui::MainWindow *ui;
    Scene* _scene = 0;
    QString _filepath;
    QString fileDialogDirectory() const;
    void updateWindowTitle();

    void addManager(Manager* manager, bool floating = true);

    /**
     * @brief createMenu creates a Menu out of Registered classes
     * @return
     */
#define CONNECT_ACTION_TYPE std::function<void(const QString&, const QAction*)>
    template<typename T> QMenu* createMenu(CONNECT_ACTION_TYPE connectAction, QString name);


    QList<QAction*> _checkableActions;
    QMenu* createToolMenu();
    QMenu* _toolMenu = 0;
    QMenu* createManagerMenu();
    QMenu* _managerMenu = 0;
    QMenu* createNewObjectsMenu();
    QMenu* _newObjectsMenu = 0;

};

#endif // MAINWINDOW_H

