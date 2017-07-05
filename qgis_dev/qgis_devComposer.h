#ifndef QGIS_DEVCOMPOSER_H
#define QGIS_DEVCOMPOSER_H

#include <QObject>
#include <QMainWindow>
#include <QAction>
#include <QToolBar>
#include <QGridLayout>
#include <QWidget>
#include <QString>
#include <QMoveEvent>
#include "ui_qgis_dev_composerBase.h"

#include <qgscomposerview.h>
#include <qgscomposition.h>
#include <qgscomposerruler.h>

#include <qgsmapcanvas.h>

class qgis_devComposer : public QMainWindow , public Ui_composerBase
{
    Q_OBJECT
public:
    //! ���ڿ������ģʽ
    enum OutputMode
    {
        Single = 0, // ֻ�������feature
        Atlas // ��������ϳ�
    };

    qgis_devComposer( QWidget *parent = 0 );
    ~qgis_devComposer();

    //! ����map canvasָ��
    QgsMapCanvas* mapCanvas();

    //! ����composer view��ָ��
    QgsComposerView* view() { return m_composerView; }

    //! ���ص�ǰ�ĺϳ�
    QgsComposition* composition() {return m_composition;}

signals:
    //! ���ű����仯�󣬾ͷ������signal
    void zoomLevelChanged();

public slots:
    //! �ϳ���ͼ�������
    void on_actionPanComposer_triggered();
    void on_actionZoomAll_triggered();
    void on_actionZoomActual_triggered();
    void on_actionZoomIn_triggered();
    void on_actionZoomOut_triggered();
    void on_actionShowFullScreen_triggered( bool checked );

    //! �ϳ���ͼ��������
    void on_actionShowGrid_triggered( bool checked );
    void on_actionToggleRulers_triggered( bool );


    //! ��ͼԪ�ع���
    void on_actionSelectTool_triggered();
    void on_actionAddShape_triggered();
    void on_actionAddMap_triggered();
    void on_actionAddArrow_triggered();
    void on_actionAddHtml_triggered();

    //! ������ǰ�ϳ�
    void on_actionExportAsImage_triggered();
    void on_actionExportAsSvg_triggered();
    void on_actionExportAsPDF_triggered();

protected:
    virtual void moveEvent( QMoveEvent* ) override;


private slots:
    void setComposition( QgsComposition* composition );

private:

    void exportCompositionAsImage( qgis_devComposer::OutputMode mode );


    QString m_title; //! �ϳɱ���

    QgsComposerView* m_composerView;
    QGridLayout* m_viewLayout;
    QgsComposerRuler* m_horizontalRuler;
    QgsComposerRuler* m_verticalRuler;
    QWidget* m_rulerLayoutFix;

    QgsComposition* m_composition; //! ��ǰ�ϳɶ���ָ��

    QWidget* mainWidget; //! ���ڵ�central widget
};

#endif // QGIS_DEVCOMPOSER_H