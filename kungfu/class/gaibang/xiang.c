// xiang.c ���
// Modify By Looklove 2000/10/21

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_mantou();

void create()
{
	set_name("���", ({"xiang zhanglao", "xiang" ,"zhanglao"}));
	set("title", HIW"ؤ�ﴫ������"NOR);
	set("gb/bags",9);
	set("mantou_count",30);
	set("gender", "����");
	set("age", 70);
	set("long", "����������ŭ������\n");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 35);
	set("con", 20);
	set("dex", 30);

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 2900);
	set("max_jing", 2900);
	set("eff_jing", 3200);
	set("neili", 4600);
	set("max_neili", 4600);
	set("jiali", 100);

	set("combat_exp", 2600000);

	set_skill("force", 240);
	set_skill("huntian-qigong", 240);
	set_skill("strike", 240);
	set_skill("dodge", 240);
        set_skill("xiaoyaoyou", 240);
	set_skill("parry", 240);
        set_skill("blade",240);
        set_skill("liuhe-daofa",220);
        set_skill("hand",220);
        set_skill("begging", 120);
        set_skill("suohou-shou",220);

	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
        map_skill("blade","liuhe-daofa");
        map_skill("hand","suohou-shou");
	map_skill("parry", "suohou-shou");
	prepare_skill("hand", "suohou-shou");

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
        	(: perform_action, "blade.sancai" :),
        	(: exert_function, "huntian" :),
        }));

	create_family("ؤ��", 18, "��������");

	set("inquiry", ([
		"ؤ��" : "����ؤ�������µ�һ��\n",
		"�Ƿ�" : "����һλ�˲���Ĵ�Ӣ�ۣ���ϧ�������ࡣ\n",
		"����һ����ͷ��" : (: ask_mantou :),
	]));
	setup();

        carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("caoxie"))->wear();
	carry_object(__DIR__"obj/gb_budai9")->wear();
}

void attempt_apprentice(object ob)
{
        if (ob->query("family/family_name")
        && ob->query("family/family_name") != "ؤ��") {
                command("say �㻹��ȥ������ɿ����ɡ�");
                return;
	}
        if ((int)ob->query("gb/bags") >= 2
        && ob->query("family/family_name") != "ؤ��" ) {
                command("say ؤ����ݲ��������ֱ��������С�ˣ�");
                command("kill "+ob->query("id"));
                return;
        }

        if((int)ob->query_skill("huntian-qigong",1) < 100){
		command("say ����������ؤ�����������Ĺ�����Դ����в�������\n");
		return;
	}
        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");

        command("recruit " + ob->query("id"));
        if (!ob->query("gb/bags")) ob->set("gb/bags", 1);
        ob->set("title",sprintf("ؤ���ܶ�%s������",
                chinese_number(ob->query("gb/bags"))) );
        ob->set("gb/fenduo","�ܶ�");
        ob->set("class","beggar");
}

string ask_mantou()
{
        object me;
        me = this_player();

        if (me->query("family/family_name") != "ؤ��")
                return RANK_D->query_respect(me) +
                "����ؤ��ú���˵���ֻ��������߳��";

        if (me->query("gb/bags") > 8)
                return RANK_D->query_respect(me) +
                "������ݣ���ô�ܺ���Ҫ�������أ�";

        if (present("mantou", me))
                return RANK_D->query_respect(me) +
                "���Լ����ﲻ������ȥ���ɣ�������Ͱ��";

        if (query("mantou_count") < 1) return "�ҽ���Ҳû���ֵ���ͷ���Լ�ȥ�ְɡ�";

        new(FOOD_D("mantou"))->move(me);
	add("mantou_count", -1);
        message_vision("$N�õ�һ������ͷ��\n",me);
        return "��ȥ�԰ɣ���ҭ����";
}	
