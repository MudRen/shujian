// Room: /d/huashan/xiuxi1.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "Ů��Ϣ��");
        set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������ֻ����
�����һ����ʰ����������Ĵ󴲣����ž�������˯����
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);

        set("exits",([
        	"north" : __DIR__"celang3",
	]));

        set("indoors", "��ɽ" );
        set("coor/x",70);
  set("coor/y",-40);
   set("coor/z",80);
   setup();
}
