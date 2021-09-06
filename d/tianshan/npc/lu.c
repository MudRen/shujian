// Npc: /d/tianshan/npc/lu.c
// By Linux

inherit NPC;
int random_walk();
string *walkrooms = ({
        "/d/tianshan/bzhanjian",
        "/d/tianshan/shizhuyan",
        "/d/tianshan/duanhunya",
        "/d/tianshan/banshan",
});

void create()
{
        
	set_name("÷��¹", ({ "meihua lu", "lu" }) );
        set("race", "Ұ��");
        set("age", 2);
        set("long", "һֻ�ɰ���÷��¹������Ѫ�Ǵ�֮�\n");
        set("attitude", "peaceful");
 
        set("str", 30);
        set("cor", 26);

        set("limbs", ({ "ͷ��", "����", "צ��", "β��" }) );
        set("verbs", ({ "bite" }) );
 
        set("combat_exp", 3000);

        set_temp("apply/attack", 50);
        set_temp("apply/damage", 10);
	set_temp("apply/defence",30);
	set_temp("apply/armor",10);
	set("chat_chance", 3);
      	set("chat_msg", ({
              (: random_walk :),
      	}) );

        setup();
}

int random_walk()
{
        mapping exits;
        string *dirs, dir;

        if( member_array(base_name(environment()), walkrooms) == -1 ) {
                message_vision("$Nһ�����ܵ��ˡ�\n", this_object());
                destruct(this_object());
        }

        if( !environment()
        || !mapp(exits = environment()->query("exits")) 
        || query("jingli") < query("max_jingli") / 2 ) 
                return 0;

        dirs = keys(exits);
        dir = dirs[random(sizeof(dirs))];
        if( member_array(exits[dir], walkrooms) == -1 ) return 0;

        command("go " + dir);
        return 1;
}
