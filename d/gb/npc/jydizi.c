// NPC: /d/gb/npc/jydizi.c ��������

#include <ansi.h>
#include <combat.h>
inherit NPC;
string ask_for_test();
void create()
{
	set_name("��������", ({"jieyin dizi", "jieyin", "dizi"}));
	set("long",
		"����һλ���ǿ����׳��������Ŀ��࣬����������һ����֪��\n"
		"��һ������ա�\n"
	);

	set("gender", "����");
	set("attitude", "friendly");

	set("inquiry",([
		"���"	: (: ask_for_test :),
		"����"	: (: ask_for_test :),
	]));

	set("age", 20);
	set("shen_type", 1);
	set("str", 30);
	set("int", 17);
	set("con", 50);
	set("dex", 21);
	set("max_qi", 500);
	set("max_jing", 200);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 40);
	set_skill("huntian-qigong", 40);
	set_skill("dodge", 50);
	set_skill("xiaoyaoyou", 50);
	set_skill("hand", 90);
	set_skill("suohou-shou", 90);
	set_skill("parry", 30);
        set_skill("liuhe-daofa",70);
        set_skill("blade",70);

	map_skill("force", "huntian-qigong");
        map_skill("blade","liuhe-daofa");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("hand", "suohou-shou");
	map_skill("parry", "liuhe-daofa");
	prepare_skill("hand", "suohou-shou");

	set("startroom","/d/gb/fenduo2");
	set("chat_chance", 3);
	set("chat_msg", ({
		"��������˵��: ����Ҫ��������Ӣ�ۣ����ؤ�\n",
		"����������������ĸ�Ħ�ŵ��档\n",
		"��������˵����������������ʿ����ؤ���Ҫ�����������顣 \n",
	}) );
  	create_family("ؤ��", 19, "����");
	setup();
        carry_object(BINGQI_D("blade"))->wield();
        carry_object(CLASS_D("gaibang/obj/gb_budai3"))->wear();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
void init()
{
	add_action("do_test", "test");
}

string ask_for_test()
{
	object me = this_player();

        if (me->query("gb_pass"))
		return "���Ѿ���ؤ������ˣ��ɱ���ҿ������Ц��\n";
	me->set_temp("pending/join_gb", 1);
	return "Ϊؤ��Ч����Ҫ��һ���Ĺ�������Ը��������ҿ���һ����(test)\n";
}

int do_test()
{
	int i;
	object me = this_player();

	if( !me->query_temp("pending/join_gb") )
		return 0;
	if (!living(this_object())) return 0;
	message_vision(
		"$N����һҾ�����������ĵ�������ָ�̡���\n\n"
		"$n˫�ֱ�ȭ����˵�������롱��\n\n",
		me, this_object() );
	for (i=0;i<6;i++){
		if (interactive(me) && me->query_temp("pending/join_gb") && living(me))
			COMBAT_D->do_attack(this_object(), me, query_temp("weapon"), 1);
		if((!living(me))||((int)me->query("qi")<(int)me->query("max_qi")/4))
			return notify_fail("���ǿ�ϧѽ�������㻹Ҫ���Ŭ����\n");
	}
	command("smile");
	command("say ��ϲ����ϲ���ӽ��Ժ������ؤ��İ����ˡ�\n");
	command("say �������ؤ����ⳤ������Ϊؤ�﹤����(ask wu about job)\n");
	me->delete_temp("pending/join_gb");
	me->set("gb_pass",1);
	return 1;
}