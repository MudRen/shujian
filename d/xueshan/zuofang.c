// Room: zuofang.c

inherit ROOM;

void create()
{
	set("short", "��ެ֯������");
	set("long", @LONG
������ެ����ʢ������Ƥë������˿ë�ֹ���Ʒҵ�����������ެ����
������������۴ӹ�ģ���Ǽ�������һ���ġ������ڳ�����Ŵִ��ţ������
�����һ�Ǽӹ��õ�Ƥë�ѵ���Сɽһ������ʮ��Ů����ͷ�ɿ��֯�Ż�ɫ��
ͬ��ë̺���ַ���죬�����в��ٻ���ʮ����ĺ��ӡ�һ���๤ģ����������
�߶�Ѳ���š�
LONG
	);

	set("exits", ([
		"east" : __DIR__"jiedao2",
	]));
        set("no_sleep_room",1);
        set("objects", ([__DIR__"npc/worker" : 3,
			__DIR__"npc/jiangong" : 1
	]));
	set("coor/x",-230);
  set("coor/y",110);
   set("coor/z",0);
   setup();
}
