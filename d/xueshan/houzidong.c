// Room: houzidong.c

inherit ROOM;

void create()
{
	set("short", "���Ӷ�");
	set("long", @LONG
���ﴫ˵�ǹ����������㻯��⨺���Ҷ�Ů����ϡ����ܺ���ĵط����Ҷ�
��ı��ϵ��к�������̬���ã����пɰ������⵽�����ǹ�ͺͺ����ʯ��ʯ
���м����ļ����Ӳ��ں�����ɪɪ������
LONG
	);

	set("exits", ([
		"westup" : __DIR__"shanlu7",
                "southeast" : __DIR__"jiaopan",
	]));
        set("outdoors", "ѩɽ");
	set("coor/x",-260);
  set("coor/y",160);
   set("coor/z",20);
   setup();
}
