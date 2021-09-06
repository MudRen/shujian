// Npc: /d/tianshan/npc/zhuji.c
// By Linux

inherit NPC;
int random_walk();
string *walkrooms = ({
        "/d/tianshan/shanlu1",
        "/d/tianshan/shanlu2",
        "/d/tianshan/shanlu3",
        "/d/tianshan/shanlu4",
});

void create()
{
        set_name("��", ({ "zhu ji", "ji" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻֻ������ɽ���ܹ����õ����񼦡�\n");
        set("attitude", "peaceful");
        set("limbs", ({ "ͷ��", "����", "ǰצ", "��צ", "β��", "���" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 500);
        
        set_temp("apply/attack", 2);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 2);
        set_temp("apply/armor", 1);

	set("chat_chance", 5);
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
