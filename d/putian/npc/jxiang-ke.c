// jxiang-ke.c �����

inherit NPC;

void create()
{
        set_name("�����", ({ "jingxiang ke", "ke" }));
        set("gender", random(2)==1 ? "����":"Ů��");
        set("age", 24 + random(50));

        set("combat_exp", 500 + random(1000));
        set("shen_type", random(50));
      	set("chat_chance", 10);
        set("chat_msg", ({ (: random_move :),}) );
        setup();
        add_money("silver", 1 + random(10));
}
