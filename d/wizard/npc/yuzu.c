// NPC: /d/wizard/npc/shitong.c
// Date: Look 99/10/25

inherit NPC;

string ask_gonglao(object me);

void create()
{
        set_name("����", ({ "yuzu" }));
        set("long", "���ǹٸ����������䣬һ�����ϵı��顣\n");
        set("age", 47);
        set("combat_exp", 20000);
        set("int", 10);
        set("con", 50);
        set("dex", 50);
        set("str", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("max_qi", 9000);
        set("qi", 9000);
        set("max_jing", 300);
        set("jing", 300);
        set("eff_jingli", 300);
        set("jingli", 300);
        set("max_neili", 300);
        set("neili", 300);
        
        set("inquiry", ([
              "�ͷ�" : (: ask_gonglao :),                        
        ]));

        setup();
        carry_object(ARMOR_D("armor/cloth"))->wear();
}

string ask_gonglao(object who)
{
        int i;
        object me=this_player();
        i = me->query_condition("killer");
        if ( !i ) return RANK_D->query_respect(me)+"û��ɱ�ˣ�����������ʲô��Ŷ�����ˣ�������ʦ��\n";
        if(random(10) > 3) return RANK_D->query_respect(me)+"����ʲô��˼���Լ������飬���Ҹ�ʲô��\n";
        message_vision("$N���Ķ�$n˵����"+RANK_D->query_respect(me)+"����" + CHINESE_D->chinese_number((i-175)/6) + "��ʱ���ͳ�ȥ�ˡ�\n",who,me);
        return RANK_D->query_respect(me)+"�ɲ�Ҫ����ɱ�޹���Ŷ��";
}
