// dizi9.c �����Ž���
#include <ansi.h>
inherit NPC;
void create()
{
        string weapon;
        set_name("�����Ž���", ({"jiao zhong","zhong"}));
        set("long","����һλ�������������ŵĽ��ڡ�\n");
        set("gender", random(2)?"Ů��":"����");
        set("attitude", "peaceful");
        set("age", 18+random(30));
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 450);
        set("max_jing", 400);
        set("neili", 500);
        set("max_neili", 500);
        set("jiaji", 1);
        set("combat_exp", 35000+(random(30000)));
        set_skill("force", 33);
        set_skill("shenghuo-shengong", 33);
        set_skill("dodge", 33);
        set_skill("piaoyi-shenfa", 33);
        set_skill("cuff", 33);
        set_skill("lieyan-dao", 35);
        set_skill("liehuo-jian", 35);
        set_skill("parry", 33);
        set_skill("blade", 33);
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("parry", "lieyan-dao");
        map_skill("blade", "lieyan-dao");
        map_skill("sword", "liehuo-jian");
        setup();
        create_family("����",39,"����");
        weapon = random(2)?BINGQI_D("changjian"):BINGQI_D("blade");
        carry_object(weapon)->wield();
        carry_object("/d/mingjiao/obj/black-cloth")->wear();
}

void attempt_apprentice(object ob)
{     
        command("say �Ǻǣ����书��΢���ɲ�����ͽ����");
        return;
}
