// Room: ��� 4
// bbb 1997/06/11
// Modify By River 98/12 
inherit ROOM;

void create()
{
        set("short", "���");
	set("long", @LONG
һ����ֱ��ʯ����ͨ��ǰ����·�ϲ�ʱ�������������ĳ�����������
�����㷢�ִ�������ε���Խ��Խ���ˣ����������������֮һΪ�������壬
���͡��ס����ᡢ���ȶ�ʮ������壬·�ԵĲ軨Ц��ӭ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "north" : __DIR__"dadao3",
	    "south" : __DIR__"beimen",
        ]));
        set("outdoors", "����");

	set("coor/x",-310);
  set("coor/y",-360);
   set("coor/z",-20);
   set("coor/x",-310);
  set("coor/y",-360);
   set("coor/z",-20);
   setup();
}
