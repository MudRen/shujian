// Room: /u/swl/songshan/shidao2.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ʯ��ͨ������̨���ϵ�ʯש�̵�ʮ�����룬��Ȼ����ɽ�����޹��ġ�
���Ը�������������ɰء�
LONG);
	set("exits", ([ 
            "south" : __DIR__"tianzhong-ge",
            "northup" : __DIR__"junji-fang",
        ]));
	set("outdoors", "��ɽ");
	set("coor/x",40);
  set("coor/y",320);
   set("coor/z",110);
   setup();
}
