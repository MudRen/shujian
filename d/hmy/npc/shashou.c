#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����ɱ��", ({ "heiyi shashou", "shashou"}));
        set("long", 
"ֻ������ò���ݣ������������һ�Ի��׳��룬������
ǰ����������һ���䵶��\n");
        set("title",HIY"�������  "HIC"�����õ���"NOR);
        set("gender", "����");
        set("age", 30);
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("pursuer", 1);
        set("shen_type", 1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        
        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 30000);
        set("shen", -1);

        set_skill("sword", 50); 
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("strike", 50);
        set_skill("force",50);
        set_skill("tianmo-zhang",50);
        
        map_skill("strike", "tianmo-zhang");
	      create_family("�������",10,"����");      

        if (random(2) == 1) {
            set("chat_chance",10);
            set("chat_msg",({
                   (: random_move :),
            }));
        }
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}
