// Room: /d/plummanor/hall.c ����
// By Jpei

inherit ROOM;

string look_painting();

void create()
{
	set("short", "����");
	set("long", @LONG
������÷ׯ�Ĵ���������ǽ����ʮ�����ϣ���Ϊ���������ǽ������һ
��������(painting)���ϱ��Ǹ����쾮���������߸���һ�����ȡ�
LONG
	);

	set("item_desc", ([
		"painting" : (: look_painting :),
		"hua" : (: look_painting :),
		"zhongtang" : (: look_painting :),
	]) );
	set("exits", ([
		"north" : __DIR__"road3",
	]));
	setup();
}

void init()
{
	add_action("do_answer", ({"answer", "huida", "da"}));
}

string look_painting()
{
	object me = this_player();
	object env = this_object();
	object shi;

	write("����������һ�����˵ı��棬ī�����죬�����۽�������ǣ��������������ī��\n");
	if (!present("danqing sheng", env) && me->query_skill("sword") > 150) {
		write("�����˸��ֱʷ�ɭ�ϣ�һ�ʱʱ��糤���Ĵ̻���\n");
		if (shi = present("shi lingwei", env)) {
			write("���ʩ����˵��������һ��������������֣���ʮ��ϲ���������л��У����ƺ��̲���һ�׼������Ľ�������\n");
			tell_room(env, me->name() + "ָ�����ã���ʩ����˵��Щʲô��\n", ({me}));
			write("ʩ����������������ׯ��һ�մ�����ģ������н������������ڣ���������ƽ����֮��������֮����Ҳ�治�����ˡ���\n");
			if (me->query_temp("pulmmanor/shi_friend") >= 18 && me->query_temp("plummanor/flag") == 4) {
				write("ʩ�������������Ȼ�ܴӴ˻��п����˽��⣬��ׯ��������Ϊ֪�����ҽ�ȥ��֪����\n");
				message_vision("$N����$nһ���֣�ת��ϲ���̵��߽�ȥ�ˡ�\n", shi, me);
				destruct(shi);
				call_out("danqing_out", 20, me);
			}
		}
	}
	return "";
}

void danqing_out(object me)
{
	object danqing, env = this_object();

	if (!objectp(me)) return;
	if (!(danqing = present("danqing sheng", env))) {
		danqing = new(__DIR__"npc/danqingsheng");
		danqing->move(env);
	}
	tell_room(env, "����������һ�˴������������һ��п����˽��������˵��۹���˲��𰡡����������У��߽�һ��������\n", ({}));
	if (!present(me, env)) {
		tell_room(env, "���˿��˰��죬��ֵص�����ʩ����˵����˭ѽ������˵��ת���ȥ�ˡ�\n", ({}));
		destruct(danqing);
		return;
	}
	me->set_temp("plummanor/flag", 5);
}

