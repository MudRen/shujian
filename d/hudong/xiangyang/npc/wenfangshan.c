// /d/city/npc/wenfangshan

inherit NPC;

int qingjiao(string arg);
 
void create()
{
        set_name("�·�ɽ", ({ "wen fangshan", "wen" }));
        set("nickname", "�¼�����");
        set("long", 
        "�������¼����ϵ������·�ɽ��\n"
        "һ����ʮ��������ߣ�ԲԲ�����ϣ���¶�����յ����顣\n");
        set("gender", "����");
        set("age", 52);
        set("attitude", "friendly");
        set("shen", -9000);
        set("str", 30);
        set("int", 30);
        set("con", 25);
        set("dex", 27);
        
        set("max_qi", 2000);
        set("max_jing", 1800);
        set("neili", 2000);
        set("neili", 2000); 
        set("max_neili", 2000);
        set("jiali", 100);
        set("combat_exp", 900000);
         

    set_skill("force", 140);
    set_skill("yijin-jing", 140);
    set_skill("dodge", 150);

    set_skill("shaolin-shenfa", 140);
    set_skill("cuff", 150);
    set_skill("wenjia-daofa", 130);
    set_skill("parry", 140);
    set_skill("blade", 120);
    set_skill("wenjia-quan", 150);
    set_skill("literate", 110);

        map_skill("force", "yijin-jing");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("cuff", "wenjia-quan");
        map_skill("parry", "wenjia-quan");
        map_skill("blade", "wenjia-daofa");
       prepare_skill("cuff", "wenjia-quan");
       prepare_skill("cuff", "wenjia-quan"); 
 
         set("inquiry", ([
                "������" : (: qingjiao :),
        ]));
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
}


int qingjiao(string arg)
{
    object me = this_player();
    int lvl = me->query_skill("wuxing-zhen", 1);

    if (!living(me)) return 0;
    if (!living(this_object())) return notify_fail("���Ȱ���Ū����˵�ɣ�\n");
    if( me->query("combat_exp")<800000)
        return notify_fail("��ľ���̫������޷�����ҼҴ�������\n");
    if( me->query_skill("force",1)<160)
        return notify_fail("��Ļ����ڹ�����̫������޷�����ҼҴ�������\n");        
    if( me->query("potential")<= 0)
    {
        command("say �������Ѿ�����ܶ��ˣ��㻹�Ǹ��������ɡ�\n");
        return 1;
    }
    if (lvl < 160)
    {
        message_vision("$N��$n����й�������İ��\n", me, this_object());
        me->receive_damage("jing", 30);
        write("�������·�ɽ��ָ�㣬�������󷨵İ����ƺ���Щ�ĵá�\n");
        me->add("potential",-(random(3)+2));
        if( me->query("potential")<0)
            me->set("potential",0);
        me->improve_skill("wuxing-zhen", 20+random(me->query_int()));
        return 1;
    }
    
    command( "say ���Ѿ�û��ʲô���Խ�����ˡ�");
    return 1;
}