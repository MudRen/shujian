// Room: yueliangmen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ʯ����С���ţ��ų����صİ����Σ���������е����һ�����£�
�Աߵ��Щ�ǳ������½����ӳ������������������ý�����䡣�ſ�����
�ֱ�����һֻ���ޣ�Ϊͭ�������һֻ������״��һֻ�̾�״��
LONG
	);

        set("exits", ([
		"east" : __DIR__"rimulundian",
		"enter" : __DIR__"juechenyuan",
	]));

	setup();
}
