#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "di xiu", "di", "xiu" }));
        set("long", "����һ����׳�ĺ��ӣ�����������ͽ�ܡ�\n");
        set("gender", "����");
        set("age", 30);
        set("per", 20);
        set("attitude", "heroism");
        set("shen_type", -1);
        set("str", 23);
        set("int", 23);
        set("con", 23);
        set("dex", 24);
        
        set("max_qi", 1500);
        set("max_jing", 1000);
        set("eff_jingli", 1000);
        set("jiali", 20);
        set("combat_exp", 700000);
        set("shen", -7000);

    set_skill("force", 100);
    set_skill("songshan-qigong", 100);
    set_skill("dodge", 100);
    set_skill("zhongyuefeng", 100);
    set_skill("strike", 100);
    set_skill("songyang-zhang", 100);
    set_skill("parry", 100);
    set_skill("sword", 100);
    set_skill("songshan-jian", 100);
    set_skill("literate", 60);
    map_skill("force", "songshan-qigong");
    map_skill("dodge", "zhongyuefeng");
    map_skill("strike", "songyang-zhang");
    map_skill("parry", "songshan-jian");
    map_skill("sword", "songshan-jian");
    prepare_skill("strike", "songyang-zhang");
    create_family("��ɽ��", 5, "����");
        set("class", "taoist");
        setup();
        carry_object(ARMOR_D("changpao1"))->wear();
        carry_object(BINGQI_D("changjian"))->wield();             
}

void attempt_apprentice(object ob)
{
     if(ob->query("shen") < 0 && ob->query("combat_exp") < 10000){
        command("say ����аħ���������������ɽ�ɣ������");
        return;
        }
     command("say �ðɣ�ʦ����Ҫ�Ҷ�����һЩ������������ɽ���ء�");
     command("recruit " + ob->query("id"));
}

