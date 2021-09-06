// NPC: CLASS_D gaibang/xi.c �ɳ���
// Modify by Looklove@sj 2000/9/19

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_yao();
string ask_dan();
#include "begger.h";
int ask_gold(object who);

void create()
{
        set_name("�ɳ���", ({"xi zhanglao", "xi", "zhanglao"}));
        set("title", HIW"ؤ��Ŵ�����"NOR);
        set("gb/bags",9);
        set("gender", "����");
        set("age", 60);
        set("long","����ؤ��������֮һ,һ������ʹ�ó����뻯��\n");
        set("attitude", "peaceful");
        set("unique", 1);
        set("str", 25);
        set("int", 18);
        set("con", 20);
        set("dex", 20);

        set("qi", 1000);
        set("max_qi", 1000);
        set("jing", 600);
        set("max_jing", 600);
        set("eff_jingli", 860);
        set("neili", 2400);
        set("max_neili", 1400);
        set("jiali", 100);

        set("yao_count",20);
        set("dan_count",20);
        set("combat_exp", 500000);

        set_skill("force", 120); // �����ڹ�
        set_skill("huntian-qigong", 120); // ��������
        set_skill("dodge", 120); // ��������
        set_skill("xiaoyaoyou", 120); // ǧ������
        set_skill("parry", 120); // �����м�
        set_skill("staff", 140);
        set_skill("fengmo-zhang",150);
        set_skill("lianhua-zhang",120);
        set_skill("strike",120);
        set_skill("begging", 90);

        map_skill("force", "huntian-qigong");
        map_skill("parry","fengmo-zhang");
        map_skill("staff","fengmo-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("strike", "lianhua-zhang");
        prepare_skill("strike", "lianhua-zhang");

        create_family("ؤ��", 18, "�Ŵ�����");

        set("inquiry", ([
                "ؤ��" : "����ؤ�������µ�һ��\n",
                "�Ƿ�" : "���������ǡ���������ǰ��������ѧ�Ʒ��ء�\n",
                "����" : "���������Ƿ壬���ǵ�ǰ�ΰ�����\n",
                "ѧ�Ʒ�" : "�Ƕ��Ǻܶ���ǰ�����ˣ�����ʱ��һ��С������ͷ������\n",
                "С��" : "�����ˣ���ǰ����Ҳ���ǵ�̫����ˣ��������ڸ��ݸ����ɡ�\n",
                "��ҩ" : (: ask_yao :),
                "�ⶾ" : (: ask_dan :),
                "�ٲݵ�" : (: ask_dan :),
                //"����" : (: ask_gold :),

        ]));
        setup();
        carry_object(__DIR__"obj/gb_budai9")->wear();
        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("caoxie"))->wear();
        carry_object(BINGQI_D("gangzhang"))->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query("family/family_name")
        && ob->query("family/family_name") != "ؤ��") {
                command("say �㻹��ȥ������ɿ����ɡ�");
                return;
        }

	if ((int)ob->query_str() <=20	) {
		command("say ���������㣬����ѧ�����ҵĹ���\n");
		return;
	}

        if ((int)ob->query("gb/bags") >= 2
        && ob->query("family/family_name") != "ؤ��" ) {
                command("say ؤ����ݲ��������ֱ��������С�ˣ�");
                command("kill "+ob->query("id"));
                return;
        }

	if( ob->query_skill("huntian-qigong", 1) < 50){
		command("say "+RANK_D->query_respect(ob) +"�Ļ��������ǲ��ǻ�������");
		return;
	}

        command("say �ðɣ�ϣ��" + RANK_D->query_respect(ob) +
        "�ܺú�ѧϰ�����书�������ڽ����д���һ����Ϊ��");
	command("recruit " + ob->query("id"));

        if (!ob->query("gb/bags")) ob->set("gb/bags", 1);
        ob->set("title",sprintf("ؤ����·ֶ�%s������",
                chinese_number(ob->query("gb/bags"))) );
        ob->set("gb/fenduo","���·ֶ�");
        ob->set("class","beggar");
}

string ask_yao()
{
        object me = this_player();

        if (me->query("family/family_name") != "ؤ��")
		return RANK_D->query_respect(me) + "����ؤ��ú�����֪�˻��Ӻ�̸��";
        if (me->query("max_neili" ) < 100)
		return RANK_D->query_respect(me) + "Ŀǰ�书��û�и�������ҩ��������Ҫ���İ����ֵܰɡ�";
        if (me->query("eff_qi",1) == me->query("max_qi",1))
		return RANK_D->query_respect(me) + "��û�����ˣ���ҩ���������˵İ����ֵܰɡ�";
        if (present("gaibang shangyao", me))
                return RANK_D->query_respect(me) + "��ҩ����������ϻ��У�������һЩ�����������ֵܰɣ�";

        if (query("yao_count") < 1) return "Ŀǰ��ҩû���ˣ��Ȼ��";

        new(MEDICINE_D("gb_shangyao"))->move(me);
        add("yao_count", -1);
        message_vision("$N���һ��ؤ����ҩ��\n",me);
        return "��������һ��ؤ����ҩ����Ч����������ȥ����ɡ�";
}

string ask_dan()
{
        object ob, me = this_player();

	if (me->query("family/family_name") != "ؤ��")
                return "��ȥ��ҽ���ɣ��ҿ�û�취��";
        if (me->query("eff_jing",1) == me->query("max_jing",1))
                return "�����û���ж����������ʲô��";
        if (query("dan_count") < 1)
                return "�������ˣ��ٲݵ�ȫ�������ˣ���ȥ�Լ��Ҵ��ɡ�";
        if (present("bai caodan", me))
                return RANK_D->query_respect(this_player()) +
                "�ٲݵ�����������ϻ��У�������һЩ�����������ֵܰɣ�ؤ��������������";

        add("dan_count", -1);
        ob = new(MEDICINE_D("bcd"));
        ob->move(me);
        return "��������һ���ٲݵ����ƽ��߳��Ӷ�����֪�Ƿ����֢����";
}
/*
int ask_gold(object who)
{
	object me = this_player();
	int gold = 0;

	if( me->query("family/family_name") != "ؤ��" ) {
		command("say " + RANK_D->query_respect(me) + "����ؤ��ú�����֪�˻��Ӻ�̸��");
		return 1;
	}

        if( (int)me->query_skill("huntian-qigong", 1) < 216 ) {
		command("say " + RANK_D->query_respect(me) + "�㲻�ú�ѧ�䣬��ô��Ϊ��ؤ�������أ�");
		return 1;
	}

	if( me->query("gb_given") >= 300 ) {
		command("say " + RANK_D->query_respect(me) + "�书���м�����Ӧ��Ϊ��ؤ�����Щ������");
		return 1;
	}

	if( (int)me->query("gb_given") + 20 < (int)me->query_skill("huntian-qigong", 1) ) {
		if( (int)me->query_skill("huntian-qigong", 1) > 300 ) 
			gold = 300 - (int)me->query("gb_given");
		else gold = (int)me->query_skill("huntian-qigong", 1) - (int)me->query("gb_given");
		gold *= 10000;

		if( (int)me->query_skill("literate", 1) < 100 ) gold *= 5; 
		else if( (int)me->query_skill("literate", 1) >= 150 ) gold *= 3; 
		else gold *= 4;

		command("interest");
		me->add("balance", gold);
		me->set("gb_given", (int)me->query_skill("huntian-qigong", 1));
		command("say ��Ȼ" + RANK_D->query_respect(me) + "�����뷨������ͽ�" + MONEY_D->money_str(gold) + "�������Ǯׯ���㶨Ҫ�ú�Ϊ��ؤ����������");
	} else command("say " + RANK_D->query_respect(me) + "����ؤ�����书Ⱥ�����֣�����ѧ���������ð���");
	return 1;
}
*/