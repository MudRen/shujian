
inherit NPC;
#include <ansi.h>;
 
void create()
{
        set_name("��ͨ��", ({ "hou tonghai", "hou", "tonghai" }));
        set("nickname", HIC"��ͷ��"NOR);
        set("long", 
        "�����ǻƺ��Ĺ�ĺ�ͨ����\n"
        "�����������¶а����һ���Ͳ��Ǻ��ˡ�\n");
        set("gender", "����");
        set("age", 35);
        set("attitude", "peaceful");
        set("str", 27);
        set("int", 20);
        set("con", 22);
        set("dex", 22);
        
        set("max_qi", 850);
        set("max_jing", 700);
        set("neili", 1100);
        set("max_neili", 1100);
        set("jiali", 20);
        set("combat_exp", 350000);
       set("shen", -3500);

    set_skill("force", 90);
    set_skill("hunyuan-yiqi", 100);
    set_skill("dodge", 90);
    set_skill("shaolin-shenfa", 100);
    set_skill("cuff", 90);
    set_skill("parry", 90);
    set_skill("taizu-quan", 100);
    set_skill("literate", 20);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shnfa");
    map_skill("cuff", "taizu-quan");
    map_skill("parry", "taizu-quan");
    prepare_skill("cuff", "taizu-quan");
 
        setup();
        carry_object("/clone/misc/cloth")->wear();
//        add_money("gold", 5);
}
