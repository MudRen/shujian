// Room: shanlu5.c

inherit ROOM;

void create()
{
	set("short", "ѩ���ŵ�");
	set("long", @LONG
  �죬������Ǧ�Ҷ��ͳ���
  ѩ�����죬��������ۡ�
  ��������ɵĸ��£����Ͳ�������
  �Ҳ��ǲ����ɽ�ȣ����䲻���ס�
  С������ѩɽ�ؾ�֮·��
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"shanlu6",
		"southwest" : __DIR__"xuelingquan",
	]));
        set("outdoors", "ѩɽ");
        set("objects", ([
         __DIR__"npc/xuebao" : 1,
        ]));
	set("coor/x",-290);
  set("coor/y",170);
   set("coor/z",20);
   setup();
}
