// Npc: /kungfu/class/shaolin/xuan-nan.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        object ob;
        set_name("���Ѵ�ʦ", ({
                "xuannan dashi",
                "xuannan",
                "dashi",
        }));
        set("long",
                "����һλ�����ü����ɮ����һϮ��˿�ػ����ġ�����ļ��ݣ�\n"
                "���ָ���צһ������˫Ŀ΢�գ�һ��û����ɵ�ģ����\n"
        );


        set("nickname", "����������");
        set("gender", "����");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 70);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1800);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 150);
        set("combat_exp", 1000000);
        set("score", 500000);

        set_skill("force", 150);
        set_skill("yijin-jing", 150);
        set_skill("dodge", 150);
        set_skill("shaolin-shenfa", 150);
        set_skill("parry", 150);
        set_skill("cuff", 150);
        set_skill("club", 150);
        set_skill("finger", 150);
        set_skill("strike", 150);
        set_skill("jingang-quan", 150);
        set_skill("zui-gun", 150);
        set_skill("yizhi-chan", 150);
        set_skill("banruo-zhang", 150);
        set_skill("buddhism", 150);
        set_skill("literate", 150);

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        map_skill("finger", "yizhi-chan");
        map_skill("strike", "banruo-zhang");
        map_skill("club", "zui-gun");
        map_skill("parry", "wuchang-zhang");

        prepare_skill("finger", "yizhi-chan");
        prepare_skill("strike", "banruo-zhang");

        create_family("������", 36, "����");

        set("inquiry", ([
                "ʮ���޺���"       : (: ask_me :),
                "�޺�����"         : (: ask_me :)
        ]));

        setup();
        if (clonep()) {                
                ob = unew(BINGQI_D("banzhu-gun"));               
                if (!ob) ob = unew("/d/shaolin/obj/qimeigun");
                ob->move(this_object());
                ob->wield();
                carry_object("/d/shaolin/obj/xuan-cloth")->wear();
        } 
}


#include "/kungfu/class/shaolin/xuan-nan.h"

