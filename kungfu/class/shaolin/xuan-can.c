inherit NPC;
//inherit F_MASTER;

string ask_me();

void create()
{
        set_name("���Ѵ�ʦ", ({
                "xuancan dashi",
                "xuancan",
                "dashi",
        }));
        set("long",
                "����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�������ݸߣ�\n"
                "�����������ƣ��ֱ۴������¶���ƺ��þ���˪��\n"
        );
        set("no_get", 1);
        set("nickname", "�޺���ִ������");
        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 70);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3000);
        set("max_jing", 3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 120);
        set("eff_jingli",2000);
        set("combat_exp", 1200000);
        set("score", 50000);
        set("unique", 1);

        set_skill("force", 150);
        set_skill("yijin-jing", 150);
        set_skill("dodge", 150);
        set_skill("shaolin-shenfa", 150);
        set_skill("parry", 150);
        set_skill("leg", 150);
        set_skill("staff", 150);
        set_skill("blade", 150);
        set_skill("sword", 150);
        set_skill("luohan-quan", 150);
//      set_skill("weituo-gun", 150);
        set_skill("wuchang-zhang", 150);
        set_skill("fumo-jian", 150);
        set_skill("buddhism", 150);
        set_skill("literate", 150);
        set_skill("ruying-suixingtui",150);
        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "ruying-suixingtui");
        map_skill("leg", "ruying-suixingtui");
        map_skill("staff", "wuchang-zhang");
        map_skill("blade", "xiuluo-dao");
        map_skill("sword", "fumo-jian");
        set("startroom","/d/shaolin/yanwutang");
      set("chat_chance", 30 );
        set("chat_msg", ({
              "���Ѵ�ʦ˵�����Ҿ��Ǹ���������Ѳ�ӣ����޺���ֵ�ڵĲ��¡�\n",
              (: random_move :),
        }));
        prepare_skill("leg", "ruying-suixingtui");
        create_family("������", 36, "����");
        set("inquiry", ([
                "�޺���ֵ��"       : (: ask_me :)
        ]));
        setup();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

void kill_ob(object me)
{
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
               (: perform_action, "leg.ruying" :)
        }));
        ::kill_ob(me);       
} 

#include "/kungfu/class/shaolin/xuan-can.h"

