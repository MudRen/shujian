// Modify By River 98/12
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����ɢ��", ({ "yuxu sanren", "yuxu", "sanren" }));
        set("title", "���������");
        set("long", "����һ��������ã��������������Դ�Щ���\n");
        set("gender", "Ů��");
        set("rank_info/respect", "����");
        set("age", 37);
        set("attitude","friendly");
        set("str", 30);
        set("dex", 35);
        set("con", 17);
        set("int", 25);
        set("unique", 1);
        set_skill("unarmed", 80);
        set_skill("force", 80);
        set_skill("qiantian-yiyang",80);
        set_skill("dodge", 80);
        set_skill("whip",80);
        set_skill("qingxu-bian", 80);
        set_skill("tianlong-xiang",80);
        map_skill("whip", "qingxu-bian");
        map_skill("force", "qiantian-yiyang");
        map_skill("dodge", "tianlong-xiang");
        
        set("combat_exp", 150000);
        set("max_qi", 900);
        set("max_jing", 400);
        set("neili", 900);
        set("eff_jingli",400);
        set("max_neili", 900);
        setup();
        carry_object(__DIR__"obj/fuchen")->wield();
        carry_object(__DIR__"obj/greenrobe")->wear();

}
