// NPC: /d/huashan/npc/dayou.c
// Date: Look 99/03/25
// Modify By Looklove@SJ 2000/01/07 for add a job
// Lklv Modify at 2001.10.18

#include <ansi.h>
inherit NPC;
string ask_job();

void create()
{
        set_name("½����", ({ "lu dayou", "lu", "dayou" }));
        set("nickname", "�����");
        set("long",
"½������ĺ��ݣ��ֳ��ļ�������ģ���������ò�������\n"
"ͬ�������е������ǻ�ɽ������һ���еĺ��֡�\n");
        set("gender", "����");
        set("age", 26);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 13);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);

        set("max_qi", 3000);
        set("max_jing", 1800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("eff_jingli", 1800);

        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 5000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("cuff", 100);
        set_skill("zixia-gong", 100);
        set_skill("huashan-jianfa", 100);
        set_skill("huashan-shenfa", 100);
        set_skill("poyu-quan", 100);
        set_skill("zhengqi-jue", 100);

        map_skill("force", "zixia-gong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");
        map_skill("cuff", "poyu-quan");

        prepare_skill("cuff", "poyu-quan");

        create_family("��ɽ��", 14, "����");

        set("inquiry", ([
              "����" : (: ask_job :),
        ]));

        setup();
        carry_object(BINGQI_D("sword/sword"))->wield();
        carry_object(ARMOR_D("armor/cloth"))->wear();
}

string ask_job()
{
        object ob, me, dao;
        me = this_player();

        if(me->query("family/family_name") != "��ɽ��")
               return "����һ�ɽ���ӣ���Щ��ǲ��鷳���ˡ�";
        //if ((int)me->query("combat_exp") >= 30000)
        if ((int)me->query("combat_exp") >= 100000)
                return "���书�ѳɣ�����ȥ��ʦ����æ�ɡ�\n";
        if (me->query("shen") < 1000)
                return "����¶�׹�, ����ǲ�������ʲô���£� ";
        if (me->query_temp("hs/kc_job"))
                return "��������ȥ����������ô����ȥ��\n";
        if(me->query_condition("job_busy"))
               return "�����ں�æ����һ�������ɡ�";

        dao = present("chai dao", me);

        if (!dao){
	        ob=new(__DIR__"obj/chaidao");
        	ob->move(me);
        	tell_object(me, "½���и���һ�Ѳ񵶡�\n");
        }
        me->set_temp("hs/kc_job",1);
        me->apply_condition("job_busy", 6+random(6));
        command("ok "+me->query("id"));
        return "�﷿��������˵������������ȱ�����������ȥ�����忳Щ�ɡ�\n";
}


