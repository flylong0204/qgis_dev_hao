#ifndef QGIS_DEV_ADDFEATURETOOL_H
#define QGIS_DEV_ADDFEATURETOOL_H

#include <QObject>
#include <QMouseEvent>
#include <QList>

#include <qgsmaptool.h>
#include <qgsmapcanvas.h>
#include "qgsmapmouseevent.h"
#include <qgsvectorlayer.h>
#include "qgsfeature.h"
#include <qgsgeometryvalidator.h>
#include <qgsvertexmarker.h>
#include "qgsrubberband.h"
#include "qgis.h"

class qgis_dev_addFeatureTool : public QgsMapTool
{
    Q_OBJECT

public:
    qgis_dev_addFeatureTool( QgsMapCanvas* mapCanvas );
    ~qgis_dev_addFeatureTool();

    enum CaptureMode // ʸ��������
    {
        CaptureNone,       // ��
        CapturePoint,      // ��
        CaptureLine,       // ��
        CapturePolygon     // ��
    };

    //! ��д���ָ���ͷ��¼�
    void canvasReleaseEvent( QgsMapMouseEvent* e ) override;

    //! ���Ҫ�غ��������� QgsVectorLayer ָ�롢��ǰҪ�أ��Լ��Ƿ�ʵʱ��ʾ
    bool addFeature( QgsVectorLayer *vlayer, QgsFeature *f, bool showModal = true );

    //! �����
    void activate() override;

    //! ��ȡ����״̬
    CaptureMode mode();

    //! ���ص�ǰ�����б��С
    int size() { return m_captureList.size(); }
    const QList<QgsPoint> &points() { return m_captureList; }

private:

    void notifyNotVectorLayer();
    void notifyNotEditableLayer();
    int addVertex( const QgsPoint& point );
    int nextPoint( const QgsPoint& mapPoint, QgsPoint& layerPoint );
    QgsRubberBand* createRubberBand( QGis::GeometryType geometryType = QGis::Line, bool alternativeBand = false );

    void startCapturing();
    void stopCapturing();
    void deleteTempRubberBand();

    /** ��Ҫ�Լ�ά�� captureList*/
    QList<QgsPoint> m_captureList;
    CaptureMode m_captureMode;
    bool mCapturing;
    /** rubber band for polylines and polygons */
    QgsRubberBand* mRubberBand;

    /** temporary rubber band for polylines and polygons. this connects the last added point to the mouse cursor position */
    QgsRubberBand* mTempRubberBand;

    QString mTip;
    QgsGeometryValidator *mValidator;
    QList< QgsGeometry::Error > mGeomErrors;
    QList< QgsVertexMarker * > mGeomErrorMarkers;

    bool mCaptureModeFromLayer;

    void validateGeometry();

    QgsVertexMarker* mSnappingMarker;
};

#endif // QGIS_DEV_ADDFEATURETOOL_H
