// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "���");
	set("long", @LONG
���߽���һ������ڹ����ŷ����黨΢Цʾ���Ľ������񣬵��ڽϻ�
�������Ҳ���Ǻ�������������Ϊ���̫�ٵ�Ե�ʰɣ���������һ�Ƚ��յĴ�
�ţ�������һ��С��ͨ���Ժ��
LONG
	);
        
	set("exits", ([ /* sizeof() == 1 */
	    "north" : __DIR__"houyuan1",
            "south" : __DIR__"yuan1",
        ]));
	set("no_clean_up", 0);

	set("coor/x",-200);
  set("coor/y",-410);
   set("coor/z",10);
   setup();
}
