// sha.c

inherit NPC;

#include <ansi.h>;
void create()
{
        set_name("ɳͨ��", ({ "sha tongtian", "sha", "tongtian" }));
        set("gender", "����");
        set("title", HIY"�ƺӰ����"NOR);
        set("nickname", HIC"��������"NOR);
        set("age", 43);
        set("str", 25);
        set("dex", 16);
        set("per", 12);
        set("long", "ɳͨ���Ǹ�ͺ�ӣ�ͷ���͹���û���ͷ����˫Ŀ������˿����
��ͻ��������һ�����ࡣ���ӱ��꣬�书ȴ�ǳ���ظߣ�������
���˲�����\n");
        set("attitude", "peaceful");
        
        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 50);
        set("combat_exp", 550000);
        set("shen", -5500);
 
        set_skill("force", 100);
        set_skill("hunyuan-yiqi", 120);
        set_skill("dodge", 100);

        set_skill("shaolin-shenfa", 120);
        set_skill("cuff", 100);
        set_skill("damo-jian", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("jingang-quan", 80);
        set_skill("literate", 30);

        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shnfa");
        map_skill("cuff", "jingang-quan");
        map_skill("parry", "damo-jian");
        map_skill("sword", "damo-jian");
        prepare_skill("cuff", "jingang-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        add_money("gold", 1);
}
