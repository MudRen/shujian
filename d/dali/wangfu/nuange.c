// Modify By River 98/12 
inherit ROOM;

void create()
{
        set("short", "ů��");
	set("long", @LONG
������������ƽʱЪϢ�ĵط������ܶ��л�¯������������ůů�ͺ͵ģ�
�������ߵ�̺���������䶼͸��һ��Ӻ�ݻ���ķ�Χ��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
	    "west" : __DIR__"lang3",
	]));

	set("objects", ([
             __DIR__"npc/dzc" : 1
        ]));
	set("coor/x",-300);
  set("coor/y",-450);
   set("coor/z",-20);
   setup();
}
