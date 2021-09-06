// Room: /dali/kedian.c
// bbb 1997/06/11
// Modify By River 98/12

inherit ROOM;
string look_sign(object me);

void create()
{
        set("short", "ӭ����");
	set("long", @LONG
��������վ�ڴ���Ǳ��ߵ�һ�ҿ͵����ҿ͵��Ǵ�����ʢ����һ
�ң�������ԭ�����˶�ϲ���ۼ������ｻ����;�ϵļ��ţ���Ҳ�����������
���������Ȥ����Ϣ�������ſڵĵط���һ����ľ��ɵ�����(sign)��
LONG
	);

	set("valid_startroom", 1);

	set("item_desc", ([
		"sign": (: look_sign :),
	]) );

	set("exits", ([
		"enter" : __DIR__"kedian2",
		"north" : __DIR__"qsjie1",
	]));

	set("objects", ([
	__DIR__"npc/xiaoer" : 1 ])
        );
	setup();
}

void init()
{
	object me = this_player();

	if(me->query_temp("xuncheng")){
		me->set_temp("dali_xc/kedian",1);
	}
}

string look_sign(object me)
{
	if (wizardp(me))
		return "����д�ţ��͹��ջ��\n";
	return "����д�ţ������ŷ���ÿҹ����������\n";
}

int valid_leave(object me, string dir)
{
	if ((string)me->query_temp("rent_paid")!="����ӭ����" && dir == "enter" )
		return notify_fail("��ô�ţ����ס����\n");
	if ((string)me->query_temp("rent_paid")=="����ӭ����" && dir == "east" )
		return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");
	return ::valid_leave(me, dir);
}
