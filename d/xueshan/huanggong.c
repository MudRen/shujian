// Room: huanggong.c

inherit ROOM;

void create()
{
	set("short", "�ʹ�");
	set("long", @LONG
���������ڽ����е�����ެ�ʹ�����Ȼ�ոս���һ�룬Ҳ���Կ�����ģ֮
�󡣵�����һ�Ѷѵ�ʯ�Ϻ�ľ�ϣ����������������������ʿ���ļල�º͸�
�ؾۼ����Ĺ��������ڵ�����������ı����Х��������������ĳ������ɹ�
�������Ǹ���ȴ�Ǹɵ���ͷ�󺹡�
LONG
	);

	set("exits", ([
		"west" : __DIR__"zanpugc",
	]));
        set("objects", ([__DIR__"npc/prince" : 1,
 			 __DIR__"npc/tufanwushi" : 4,]));
	set("coor/x",-210);
  set("coor/y",120);
   set("coor/z",0);
   setup();

}
