// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "������Ұ");
	set("long", @LONG
���������Ұ���ϣ���ʱ�Ĵ������������ű�Ҳ�����������֮���С��
�����·�ϣ�������Ŀ�������
LONG
	);
        set("outdoors", "����");
	set("exits", ([ 
	    "west" : __DIR__"shangang",
	    "east" : __DIR__"xiaodao1",
        ]));
	set("no_clean_up", 0);

	set("coor/x",-60);
  set("coor/y",-60);
   set("coor/z",0);
   setup();
}
