inherit ROOM;

void create()
{
        set("short", "����̨");
        set("long",@LONG
����̨��һ������ƽ̨���������׼ҵ�����ϰ���յĵط���
̨�߰���ľ׮��÷��׮��ɳ����ɳ���������ʩ�͸���ɮ��������
����������׼ҵ�������һ���໥�д衣
LONG);
        set("outdoors","������");
        set("exits", ([
                "eastdown" : __DIR__"3wg",
                "west" : __DIR__"longxiang4",
	        "northup" : __DIR__"longxiang2",
                "southdown" : __DIR__"longxiang3",
           
       	]));
       
        setup();
}
