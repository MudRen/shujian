// dizi1.c ��ľ�����
#include <ansi.h>
inherit NPC;
int hiting_ob(object ob);
void moving_ob(object ob);
void create()
{
        set_name("��ľ�����", ({"jiao zhong","zhong"}));
        set("long","������İ�С�����۴�׳��������Բ�����ֱֳ��У�\n"+
                   "��һ��ɫʥ�£��ƺ���һ�����ա�\n");
        set("gender", "����");
        set("attitude", "peaceful");
        set("age", 35);
        set("shen_type", 0);
        set("str", 25);
        set("int", 20);
        set("con", 20);
        set("dex", 25);
        
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 500);
        set("jiaji", 50);
        set("combat_exp", 50000+(random(50000)));
        set("score", 1);
        set_skill("force", 50);
        set_skill("shenghuo-shengong", 50);
        set_skill("dodge", 50);
        set_skill("tiyunzong", 50);
        set_skill("cuff", 50);
        set_skill("lieyan-dao", 50);
        set_skill("parry", 50);
        set_skill("blade", 50);
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("parry", "lieyan-dao");
        map_skill("blade", "lieyan-dao");
        setup();
        create_family("����",39,"����");
        carry_object(BINGQI_D("blade"))->wield();
        carry_object("/d/mingjiao/obj/black-cloth")->wear();
}

void attempt_apprentice(object ob)
{     
        command("say �Ǻǣ����书��΢���ɲ�����ͽ����");
        return;
}

#include "dizi.h";
