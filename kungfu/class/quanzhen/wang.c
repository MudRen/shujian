// wang.c ������
//Modified By action@SJ 2009/2/21

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_qxbj();

void create()
{
	      object ob;
        set_name("������", ({ "wang chongyang", "wang", "chongyang" }));
        set("long", @LONG
������ȫ��̵Ŀ�ɽ��ʦ���״��ƽ���������
���ˡ�������ƮƮ�����ۻ��䣬üĿ��񳣬��
��Щ�ɷ���ǵ�ζ����������һǻ��Ѫ����Ч
���������������ϧ��͢���ܣ����Ǳ��Ļ���
�䣬���ʱ�ִӵ��¾�������������������
�Ĵ�����Ӷ��ִ�ȫ��̡�
LONG);
        set("title", "ȫ���ɿ�ɽ��ʦ");
        set("nickname", HIW "����ͨ" NOR);
        set("age", 76);
        set("gender", "����");
        set("class", "taoist");
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 33);
        set("int", 35);
        set("con", 38);
        set("dex", 33);
        set("max_qi", 20000);
        set("max_jing", 50000);
        set("neili", 200000);
        set("jingli", 20000);
        set("max_neili", 200000);
        set("eff_jingli", 20000);
        set("jiali", 250);
        set("combat_exp", 30000000);
        set("score", 500000);

        set_skill("force", 500);      
        set_skill("xiantian-gong", 500);
        set_skill("dodge", 500);
        set_skill("jinyan-gong", 500);
        set_skill("parry", 500);
        set_skill("strike", 500);
        set_skill("haotian-zhang", 500);
        set_skill("sword", 500);
        set_skill("quanzhen-jianfa", 500);

        set_skill("taoism", 200);
        set_skill("literate", 380);
        set_skill("medicine", 200);
	      set_skill("tiangang-beidouzhen", 200);
	        
        map_skill("force", "xiantian-gong");
        map_skill("sword", "quanzhen-jianfa");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "haotian-zhang");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");

        create_family("ȫ���", 1, "�ƽ�");

        set("inquiry", ([
                "ȫ���"     : "��ȫ��������µ����������ڡ�",
                "���Ǳ���" : (: ask_qxbj :),
                "�𴦻�"     : "�����Ҷ�ͽ�ܣ�������������",
                "�ܲ�ͨ"     : "������ʦ�ܣ������ֲ�֪����������ȥ�ˡ�",
                "һ�ƴ�ʦ"     : "��ԭ�Ǵ���λ�ү����ϧ���ǲ�������ʦ���ǵ��������ˡ�",
                "��ҩʦ"     : "�����һ�������ѽ��",
                "ŷ����"     : "�ߣ��ߣ���",
                "����"     : "��˵��������ؤ������ˣ���ļٵ�ѽ���þ�û�����ˡ�",
        ]));

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "strike.lian" :),
                (: perform_action, "strike.sanqing" :),
                (: perform_action, "strike.ding" :),
                (: perform_action, "strike.qixing" :),

        }));

        set_temp("apply/damage", 100);
        set_temp("apply/armor", 200);

        setup();
        if (clonep()) {
		ob = unew(BINGQI_D("sword/qixing-jian"));
		if (!ob) ob = unew(("clone/weapon/zhujian"));
		ob->move(this_object());
		ob->wield();
    carry_object("/d/quanzhen/npc/obj/greenrobe")->wear();
	}
}

void attempt_apprentice(object ob)
{
      if(ob->query_skill("xiantian-gong",1) < 180 ||
         ob->query_skill("taoism",1) < 150 ||
         ob->query_int() < 40 ||
         ob->query("shen")<300000){
        command("say ����书����ѧ�ķ������ԡ������������������ٻ�ȥ�����ɡ�");
        return;
        }

     command("say �����������ʶ��ɴ����²����Ҿ����������ͽ���ˡ�");        
     command("say �ðɣ�ƶ�����������ˡ�");
     command("recruit " + ob->query("id"));
     ob->set("title", HIW"ȫ������������״�����"NOR);
     ob->set("class","taoism");
}

string ask_qxbj()
{
	object me=this_player() , weapon;

        if (me->query("family/master_name") != "�𴦻�" && me->query("family/master_name") != "������")
		return "�㲢����ȫ����𴦻����ӣ����ܽ����ɱ����������㡣";
        weapon = present("qixing jian", this_object());
	if (!objectp(weapon))
		return "���ǽ��Ѿ�����ʦ��������,���ڲ��������";
	command("unwield qixing jian");
	command("give qixing jian to " + me->query("id"));
	return "�����ǽ��͸����ˣ����Ҫ���Ʊ��ܺã�";
}
