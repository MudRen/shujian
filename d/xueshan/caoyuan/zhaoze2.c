// Room: zhaoze2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����������ɢɢ���Ӳݺ�һЩСˮ�ӣ�ˮ�����ˮƽ�������ǡ�����
��һ��ļž��������ϵ�������û�У���ž��������޾���ɱ�������֮
��ȫ�����࣬˿��Ҳ������������������������ͨ�쳹�׵��书Ҳ���޼�
���£�Խ�������ݵ�Խ�졣
LONG
	);
	set("exits", ([
		"north" : __DIR__"caohai5",
		"south" : __DIR__"zhaoze"+(random(3)+1),
		"west" : __DIR__"zhaoze2",
		"east" : __DIR__"caohai"+(random(6)+1),
	]));
	set("outdoor","���ԭ");
	setup();
}

void init()
{
	object me;
	me = this_player();
	if (userp(me) && me->query_skill("dodge") < 100) {
		message_vision("$N���ý���һ��˫���Ѿ��������$N��������ѽŰγ���������ݵø����ˡ�\n",me);
		message_vision("$Nֻ����һ�ɺ����ӽ���ð���������������ˡ�\n",me);
		me->set_temp("last_damage_from", "����������Ϣ");
		me->die();
	}
}
