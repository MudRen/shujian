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
       
        set("coor/x",-400);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}
