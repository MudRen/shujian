// heilinbofu.c ���ֲ���
// by iceland

#include <ansi.h>
inherit NPC;

string ask_for_join();

void create()
{
	set_name("���ֲ���", ({"heilin bofu","heilinbofu","heilin","bofu"}));
	set("long",
                "������������������������������ĺ��⣬һ˫�̶�С��\n"
                "���������ش����š�\n"
	);

        set("title", HIY "�����µ�ʮ��������" NOR);
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "huanxi");

	set("inquiry",([
		"����"	: (: ask_for_join :),
		"�ܽ�"	: (: ask_for_join :),
	]));

	set("age", 30);
	set("shen_type", -1);
	set("str", 25);
	set("int", 15);
	set("con", 25);
	set("dex", 20);
	set("max_qi", 450);
	set("eff_jing", 200);
	set("max_jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 20);
	set("combat_exp", 30000);
	set("score", 1000);
	set("unique", 1);

	set_skill("force", 30);
	set_skill("longxiang-boruo", 30);
	set_skill("dodge", 30);
	set_skill("yuxue-dunxing", 30);
	set_skill("claw", 30);
	set_skill("tianwang-zhua", 30);
	set_skill("parry", 30);
	set_skill("huanxi-chan", 30);
	set_skill("literate", 30);

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("claw", "tianwang-zhua");
	map_skill("parry", "tianwang-zhua");

	prepare_skill("claw", "tianwang-zhua");

	create_family("������", 13, "����");

	setup();

        carry_object(__DIR__"obj/qinxiu-jiasha")->wear();
}

void init(){add_action("do_kneel", "kneel");}

string ask_for_join()
{
	object me;

	me = this_player();

	if (me->query("family/family_name") != "������")
		return RANK_D->query_respect(me) + "�����ڿ���Ц�ɡ�\n";

	if( (string)me->query("class")=="huanxi" )
		return "���Ѿ����㿪̳�ܽ���ˣ�����ȱ��˶�һ�Σ���ɲ��С�\n";

	if( (string)me->query("gender") == "����" )
		return "ʩ�������ȱ����˵�����ն����������ǡ���\n";

	if (me->query_temp("pending/join_huanxi"))
		return "�ϵ㣬�����µ�ʱ������������ǡ�\n";
        
	me->set_temp("pending/join_huanxi", 1);
	return "�������������̷ϲ�������(kneel)�ܽ䡣\n";
}

int do_kneel()
{
	object me = this_player();

	if( !me->query_temp("pending/join_huanxi") )
		return 0;

	message_vision("$N������ͷ�����������ع���������\n\n",me);
        message_vision("���ֲ����ͳ�������������ü��Ŀ��Χ�������˼�Ȧ�����������дʡ�\n\n",me);
        message_vision("���ֲ���Щ��ˮ����$Nͷ�ϣ�ɽ��һ����$N���ɵô��˼�����ս��\n\n",me);
        message_vision("���ֲ�������Խ��Խ�ߣ���ͷ�������ܵĺ�ˮ���ƺ����˺ܴ��������\n\n",me);
        message_vision("���ֲ�������һ�������ѷ����Żػ��У���������˲����ϵĺ�ˮ��\n\n",me);
	command("smile");
	command("say �������ܽ䷨�������ˣ��ӽ��Ժ�ϲ����ᱣ����ġ�\n");
	me->delete_temp("pending/join_huanxi");
	me->set("class", "huanxi");
        return 1;
}
