// ���� by leontt

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

string axe();
string strike();
string ask_axe();

void create()
{
        set_name("����", ({ "qiao zi", "qiao", "zi" }) );
        set("long",
		"������������һ���ɲ���������һ�����ӣ�����ȥ��һ���Է�\n"+
		"ֻ������ɫ��׳����̬������������������Ǵ󽫾��а������磬\n"+
		"�������ֲ����Ѷ�����ɽ���Բ񣬱ص����Ǹ�߳����Ƶ�ͳ�� \n"+
		"Ԫ˧��\n");
        set("gender", "����" );
        set("age", 40);
        set("str", 30);
        set("con", 30);
        set("dex", 25);
        set("int", 25);
        set("per", 20);
        set("attitude", "friendly");

        set("chat_chance", 3);
	set("chat_msg", ({
		"���ӳ��������ǳؾ㻵��Ӣ�۰��ڣ����������ཻ��������˥����Ϊ������\n",
		"���ӳ��������ƼҲ�����Ұܣ���̬�����Ʊ�ġ�����Ҳ����ز�٣�Ҳ����ز��\n",
		"���ӳ�������������ϣ�ƾ��ң����������������ɥ�����Բԣ�ˮãã����̨�������˽���ǧ��תͷ������������Ҳ���ó�������Ҳ���ó�����\n",
	}));

        set("max_qi", 5000);
        set("max_jing", 2800);
        set("eff_jingli", 3600);
        set("neili", 8000);
        set("qi", 5000);
        set("jingli", 3600);
        set("max_neili", 8000);
        set("jiali", 150);

	set("combat_exp", 2300000);
	set("score", 50000);

        set_skill("parry", 280);
        set_skill("dodge", 280);
        set_skill("force", 280);
        set_skill("axe", 280);
        set_skill("literate", 200);
        set_skill("strike", 280);
        set_skill("qingyan-zhang", 280);
        set_skill("qiantian-yiyang", 280);
        set_skill("pangen-fu", 280);
        set_skill("tianlong-xiang", 280);
        set_skill("finger", 200);
        set_skill("yiyang-zhi", 200);
        set_skill("buddhism", 140);
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "yiyang-zhi");
        map_skill("axe", "pangen-fu");
        map_skill("force", "qiantian-yiyang");
        map_skill("strike", "qingyan-zhang");
        map_skill("finger", "yiyang-zhi");
        prepare_skill("finger","yiyang-zhi");

	set("chat_chance_combat", 10);
	set("chat_msg_combat",({
		(: perform_action, "axe.jingtian" :),
		(: exert_function, "qi" :)
	}));

	create_family("������", 14, "�׼ҵ���");

        set("inquiry", ([
		"name": "�������ʲô? �������ʲô�����ŷ������ʲô��ϵ��",
		"here": "�������Ҳ����˵�ģ�",
		"��������" : (: axe :),
		"����" : (: ask_axe :),
        ]));
        setup();
        carry_object("/clone/armor/b_cloth")->wear();
        carry_object("/clone/weapon/axe")->wield();
}

string ask_axe()
{
        object me = this_player();

        if ((string)me->query("gender") == "Ů��" )
                 return RANK_D->query_respect(me) + "��Ů�����벻Ҫ���ҿ�������Ц!";
        if ((int)me->query_skill("qiantian-yiyang",1) < 100  )
                return RANK_D->query_respect(me) + "Ǭ��һ�������֮��Һ��㽻����";
        if (me->query_str() < 25)
                return RANK_D->query_respect(me) + "Ҫѧ�ҵĿ��ұ��죬���������ߣ����ƺ����ʲ�����";
        if ((int)me->query("job_time/����") < 300)
                return RANK_D->query_respect(me) + "Ϊ���������������Ļ���������Ŭ�����ɣ�";
        if (!me->query("tls"))
                return RANK_D->query_respect(me) + "��û�г��ң�����ֱ�Ӱ���Ϊʦ�����ý�����";
        if (me->query_skill("pangen-fu",1) > 1)
                return RANK_D->query_respect(me) + "�Ѿ�ѧ�����̸���ḫ������Ҫ�����ﵷ�ң�";
        if (me->query("pgf/jiaohuan"))
                return RANK_D->query_respect(me) + "�Ѿ��������ˣ���Ҫ���⵷�ң�";

	me->add("combat_exp", -15000);
	me->set_skill("pangen-fu",91);
	me->set("pgf/jiaohuan",1);
	tell_object(me, HIY "\n����(15K) ����ֵ����(91)�����̸���ḫ(pangen-fu)��\n" NOR);
	return "���������Ѿ��������ˣ��ɲ�Ҫ���Ŷ��";
}

string axe()
{
        mapping fam = this_player()->query("family");
        object ob;

	if(!fam || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player())+"�뱾��������������֪�˻��Ӻ�̸��";
	if(this_player()->query_skill("axe",1) > 100)
		return "��ĸ����Ѿ���һ�������ˣ��Ȿ�����ûʲô�ã������������˰�";
	ob = unew("/clone/book/axe-book");
	if(!clonep(ob))
		return "�������ˣ��ҵġ������������Ѿ������������ˡ�";
	if(clonep(ob) && ob->violate_unique()){
		destruct(ob);
		return "�������ˣ��ҵġ������������Ѿ������������ˡ�";
	}
        ob->move(this_player());
	return "�ðɣ��Ȿ���������������͸����ˡ�";
}

void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") == "Ů��" ){
                command ("say �Ҵ����书��Ҫ����֮�壬С�����ҿɲ��հ�!");
                return;
        }
        if (ob->query("tls")){
                command ("say ���Ѿ��������³��ҵ����ˣ��Ҳ����������ˣ�\n");
                return;
        }
        if ((int)ob->query_skill("qiantian-yiyang",1) < 50 ){
                command ("hmm");
                command ("say ��Ǭ��һ�������֮��ҿɲ�����?");
                return;
        }
        if (ob->query_str() < 25){
                command("say Ҫѧ�ҵĿ��ұ��죬���������ߣ����ҿ�" + RANK_D->query_respect(ob) + "�������ƺ�������");
                return;
        }
/*
        if ((int)ob->query("job_time/����") < 50){
                command ("say �ҿ���Ϊ���������������Ļ���������Ŭ�����ɣ�");
                return;
        }
*/
        command("say �ţ����㻹�Ǹ�ѧ����ϣ��Ҿ�������ɣ�");
        command("giggle1");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
        ob->set("title","�����ʮ�Ĵ�����");
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}
