// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "��Ժ");
	set("long", @LONG
���˺�ԺС�ᣬ���Ǽ��ª��С���ӣ����Ϸ��ż������ţ����׵�������
����һ���������ƣ����иߴ����ɮ��
LONG
	); 
	set("exits", ([ /* sizeof() == 1 */
	    "south" : __DIR__"dadian",
        ]));

        set("objects", ([
        	__DIR__"npc/huangmei" : 1,
        ]));

	set("coor/x",-200);
  set("coor/y",-400);
   set("coor/z",10);
   setup();
}
