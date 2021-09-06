// Npc: /d/putian/npc/wuseng.c ��ɮ
// Lklv 2001.9.10

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��ɮ", ({
                "wu seng",
                "seng",
                "wu",
        }));
        set("long",
                "һλ��ĸߴ����ɮ�����۴�׳��������Բ����һ������ա�\n"
        );

        set("gender", "����");
        set("attitude", "peaceful");
        set("class", "bonze");
        set("no_quest", 1);

        set("age", 25+random(12));
        set("shen_type", 1);
        set("str", 25+random(20));
        set("int", 20+random(10));
        set("con", 20);
        set("dex", 25+random(10));
        set("max_qi", 500+random(800));
        set("max_jing", 300+random(800));
        set("neili", 500+random(400));
        set("max_neili", 500+random(100));
        set("jiaji", 10+random(40));
        set("combat_exp", 100000+random(100000));
        set("score", 1);

        set_skill("force", 100+random(50));
        set_skill("yijin-jing", 100+random(50));
        set_skill("dodge", 100+random(50));
        set_skill("shaolin-shenfa", 100+random(50));
        set_skill("banruo-zhang", 100+random(50));
        set_skill("luohan-quan", 100+random(50));
        set_skill("parry", 100+random(50));
        set_skill("cuff", 100+random(50));
        set_skill("strike", 100+random(50));

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("strike", "banruo-zhang");
        map_skill("parry", "luohan-quan");
        map_skill("cuff", "luohan-quan");
        prepare_skill("cuff","luohan-quan");
	prepare_skill("strike","banruo-zhang");

        set("chat_chance", 3);
        set("chat_msg", ({ (: random_move :),}) );

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "strike.qiankun" :),
		(: perform_action, "strike.chaodu" :),
	}));

        setup();

        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/sengxie")->wear();
        carry_object(__DIR__"obj/huwan")->wear();
        carry_object(__DIR__"obj/huxin")->wear();
        carry_object(__DIR__"obj/zhitao")->wear();
        carry_object(__DIR__"obj/huyao")->wear();
}

void init()
{
        object me, ob;

        ::init();

        ob = this_player();
        me = this_object();

	if (interactive(ob) && ob->query_temp("target_putian")){
		command("say �󵨿�ͽ�����Ҵ���������������Ұ������");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);

        }
}
