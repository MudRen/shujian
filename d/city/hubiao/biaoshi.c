// NPC: biaoshi.c
// Date: Look 99/04/25

inherit NPC;

string* names = ({
        "����ͬ",       "�粨��",       "��ұǬ",       "�˰ٴ�",
        "��Ұ��",       "ΤһЦ",       "�ܵ�",         "��ң",         "����",
        "����ͤ",       "������",
        "�ⳤ��",       "������",       "�ɳ���",       "�γ���",       "������",
});
string ask_me1();
string ask_me2();

void create()
{
        set_name("��ͷ", ({ "biao tou", "biaoshi", "biaotou" }));
        set("nickname", "�ĺ�Ϊ��");
        set("long", 
"���Ǹ�������͵���ʦ�������ʱ�򴳵������������������ˣ��ڴ˵ؿ���һ�������ھ֡�\n"
"һ��������ʵ�˵á�\n");
        set("gender", "����");
        set("age", 68);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 20);
        set("str", 28);
        set("int", 24);
        set("con", 20);
        set("dex", 20);
        
        set("max_qi", 3000);
        set("max_jing", 1800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("eff_jingli", 1800);

        set("jiali", 50);
        set("combat_exp", 500000);
        set("score", 5000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("strike", 100);
        set_skill("cuff", 100);

        set_skill("taizu-quan", 100);
        set_skill("tiyunzong", 100);

        map_skill("dodge", "tiyunzong");
        map_skill("parry", "taizu-quan");
        map_skill("cuff", "taizu-quan");

        set("inquiry", ([
                "����" : (: ask_me1 :),
                "����" : (: ask_me2 :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

string ask_me1()
{
        if (this_player()->query("combat_exp") <1000000)
                return "���ڿ���һ��ʮ��Σ�յĹ��������书�еͣ����ǲ���ʤ�ΰɡ�";
        this_player()->set_temp("pass",1);
        return "�ҿ�"+RANK_D->query_respect(this_player())+"�񹦳��ɣ�����ھ�����ܶ࣬���������һ������Σ�";
}

string ask_me2()
{
        int number;
        object me,ob,ob_flag;
        me = this_player();
        if (!me->query_temp("pass"))
                return "�뵱���Ҵ����������ε����磬�����������ˣ�����Ҳ�գ�";
        if (me->query_temp("mubiao")){
                command("kick " + me->query("id"));
                return "�ղ����㻤�͵������������ȥ�ˣ�";
        }
        if (me->query_condition("husong_job")>0)
        	return "������ھֵ����Լ��������ء�";
        if (me->query_condition("job_busy")>0)
        	return "������ھֵ����Լ��������ء�";
        number = random(sizeof(names));
        ob = new(__DIR__"wife.c");
        ob->move(environment(me));
//      ob->set_leader(me);
        ob_flag = new(__DIR__"flag.c");
        ob_flag -> move(me);
        me->set_temp("mubiao",names[number]);
        ob->set_temp("mubiao",names[number]);
        me->set_temp("killed",0);
        me->set_temp("husongjob",ob);
        me->apply_condition("husong_job", 30);
        tell_object(me, "��ʦ������һ�����졣\n");
        return "�ðɣ�����ͽ�����һ��������ȥ���Ұ�"+ob->query("name")+"�͵�"+names[number]+"���";
}
