// NPC: feitian.c ������
// Modify By Looklove 2000/10/17
// Modify by leontt 2000/10/22
// By Spiderii�޸�ask fen������
inherit NPC;
inherit F_MASTER;

string ask_fen(object);
string ask_biao();

void create()
{
        set_name("������", ({ "feitian zi", "feitian", "zi" }) );
        set("gender", "����" );
        set("nickname", "��������ʦ��");
        set("age", 28);
        set("long", "���ºŷ��죬�Ṧ�������Ѿ����˺ܸߵĵز���\n");
        set("env/wimpy", 40);
        set("str", 20);
        set("dex", 30);
        set("con", 19);
        set("int", 15);
        set("shen", -1400);
        set("biao", 10);
        create_family("������", 2, "����");
                                                       
        set_skill("huagong-dafa", 40);
        set_skill("strike", 30);
        set_skill("chousui-zhang", 30);
        set_skill("force", 40);
        set_skill("dodge", 50);
        set_skill("zhaixingshu", 60);
        map_skill("dodge","zhaixingshu");
        map_skill("force","huagong-dafa");
        map_skill("strike","chousui-zhang");
        map_skill("parry","chousui-zhang");
        prepare_skill("strike", "chousui-zhang");

        set("combat_exp", 80000);
        set("max_qi", 500);
        set("max_jing", 300);
        set("neili", 600);
        set("max_neili", 600);
        set("attitude", "peaceful");
        set("inquiry", 
                ([
                      "�����" : (: ask_fen,"yao" :),
                      "���Ƿ�" : (: ask_fen, "yao3" :),
                      "���׷�" : (: ask_fen, "yao2" :),
                      "���׷�" : (: ask_fen, "yao1" :),
                      "׷����" : (: ask_biao :),        
                      "biao" : (: ask_biao :),
                ]));
        
        setup();
        carry_object(ARMOR_D("pink_cloth"))->wear();
        add_money("silver", 10);
}
void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
        mapping myfam = (mapping)me->query("family");
        if(myfam && myfam["family_name"] == "������") command("bow " + me->query("id"));
        else if(me->query("combat_exp") < 100000) command("hmm " + me->query("id")); 
        else command("hi " + me->query("id"));
}
void attempt_apprentice(object ob)
{
    command("hehe");
    command("say �ҿ�û���������㡣");
    return;
}

string ask_biao()
{
        object ob = this_player(),obj;
 
        if (ob->query("family/family_name") != "������")
                return RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��";

        if (ob->query("combat_exp") < 400000)
                return RANK_D->query_respect(ob) + "����̫�����Ҳ���˷ѣ��������������˰ɡ�";
 
        if (this_player()->query("max_neili") < 1000)
                return RANK_D->query_respect(ob) + "��������������ʱ�������ɡ�";

        if (present("zhuihun biao", ob))
                return RANK_D->query_respect(ob) + "���������ϲ���������ô����Ҫ�ˣ�����̰�����ᣡ";
        if (ob->query_temp("zh/busy")>0)
                return RANK_D->query_respect(ob) + "��ո�Ҫ������ô����Ҫ�ˣ�����̰�����ᣡ";

        if (query("biao") < 1) return "�Բ���׷�����Ѿ������ˣ��㲻���ٵ��ˡ�";
 
        obj = new("/clone/weapon/zh_biao");
        obj->move(ob);
        ob->set_temp("zh/busy", 1);
        add("biao", -1);
 
        call_out("delete_zhbiao", 600, ob);

        message_vision("$N�õ�һö׷���ڡ�\n", ob);
        return "�ðɣ�������ô���ɣ���ö׷���ھ��͸���ɡ�";
}

void delete_zhbiao(object me)
{
        if ( objectp(me) ) me->delete_temp("zh/busy");
}

string ask_fen(string name)
{
        object me;
        me = this_player();
        
        if ( me->query("family/family_name") != "������")
                return RANK_D->query_respect(me) + 
                "�㲻�������޵��ӣ��˻��Ӻ�˵��";
              
        if ((int)me->query_skill("huagong-dafa",1) < 80)
                return RANK_D->query_respect(me) + 
                "��Ļ����󷨲������ò�����Щ������������ɶ�����";
                
        if ((int)me->query_temp("fen/asked")>21){
                call_out("delete_fen", 60, me); 
                return "�ղ��㲻���ʹ���ô��";
        }
        
        new("/d/xingxiu/obj/"+name)->move(me);
        me->add_temp("fen/asked",1);
        message_vision("��������ɫ���죬����$Nһ��Сֽ����\n",me);
        return "�ٺ١���ȥ�ɣ�����Ǻö�����";
}

void delete_fen(object me)
{
        if (objectp(me)) me->delete_temp("fen/asked");
}

