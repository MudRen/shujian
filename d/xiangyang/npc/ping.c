#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
int ask_quest(object);
int ask_me();

void create()
{
        set_name("ƽһָ", ({"ping yizhi", "ping"}));
        set("long",
                "�����ǽ�����������ɱ����ҽƽһָ��\n"
                "ɱһ�ˣ���һ�ˣ������Ȿ���⡣\n");
        set("title",HIR"ɱ����ҽ"NOR);
        set("rank_info/rude", "��ӹҽ");
        set("attitude","friendly");
        set("no_bark",1);
        set("str", 20);
        set("dex", 20);
        set("con", 20);
        set("int", 20);
        set("per", 20);
        set("gender", "����");
        set("age", 47);
        set("shen_type", 0);

        set("unique", 1);
        set("no_get","ƽһָ�������̫���ˡ�\n");
        set("vendor_goods", ({
                 (["name": MEDICINE_D("huiyang"), "number":3]),
                 (["name": MISC_D("xionghuang"), "number":100]),
                (["name": MEDICINE_D("jinchuang"), "number": 5]),
                (["name": MEDICINE_D("jingmai/jingmai-book3"), "number": 1]),
        }));
        set("combat_exp", 1000000);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("eff_jingli",5000);
        set("max_jingli",5000);
        set("eff_jing",5000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali",50);

        set_skill("force", 200);
        set_skill("bihai-chaosheng", 200);
        set_skill("dodge", 200);
        set_skill("suibo-zhuliu", 200);
        set_skill("parry", 200);
        set_skill("finger", 300);
        set_skill("tanzhi-shentong", 300);
        set_skill("qimen-bagua", 200);

        map_skill("force", "bihai-chaosheng");
        map_skill("dodge", "suibo-zhuliu");
        map_skill("finger", "tanzhi-shentong");
        map_skill("parry", "tanzhi-shentong");

        prepare_skill("finger", "tanzhi-shentong");

        set("inquiry", ([
                "����ѧ": "��ô��������̵�ô��",
                "���": (: ask_quest :),
                "ɱ��": (: ask_quest :),
                "����" : (:ask_me:),
        ]));

        set("waiting",0);

        setup();

        carry_object(ARMOR_D("changshan"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}


void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
       if(!ob || environment(ob) != environment()) return;
       if((ob->query("eff_qi")*100 / ob->query("max_qi") < 5)
          && (ob->query_skill("jingmai-xue",1)<170)
          && (ob->query_skill("jingmai-xue",1)>=160)) {
                command("ah");
                command("say ����������⣬�������ʵ��̫�����ˡ�");
                command("say �����������Ʒ������˵���ľ�����");
                command("consider");
                command("say ��ľ���ѧ�Ѿ����൱�����ˣ����Ȿ�زص���������ȥ�о��о�����취���ưɣ�");
                message_vision(HIY"$N����$nһ�������������\n"NOR, this_object(), ob);
                new("/clone/medicine/jingmai/jingmai-book7")->move(ob);
        }
}

int ask_quest(object me)
{
        int i;
        object *list;
        object target;

        if (this_player()) me = this_player();
        if (!me) return 0;
        if (me->query_temp("count")>10) {
                command("say �������벻��ʲô�˺�ɱ����ȵ����ʰɡ�");
                me->delete_temp("count");
        return 1;}
        if (me->query_temp("ping_quest")) {
                command("say ��ɱ�ˣ��Ǿ����ˣ�������Ҳ��û����ʲô��");
                delete("waiting");
                return 1;}
        if (query("waiting")) {
                command("say ��ȵȰɣ����ڵ����ء�");
                return 1;}
        if (me->query_skill("jingmai-xue",1)>=170) {
                command("say Ҫ����ɱ�ˣ���ɱ�����پ��㣬�����ⲻ��");
                return 1;}
        if (me->query_skill("jingmai-xue",1)>=160 && me->query_skill("jingmai-xue",1)<170) {
                command("say ��ľ���ѧ�Ѿ������ˣ��������ʲô���������Ҳ�����ˡ�");
                return 1;}
        if (me->query("combat_exp")< 850000 ) {
                command("say �㾭��̫�ͣ�ѧ��Ҳû�á�");
                return 1;}
        if (me->query_skill("jingmai-xue",1)<150) {
                command("say �㾭��ѧ����̫�ͣ��������ġ�");
                return 1;}
        if (me->query_int() < 40) {
                command("say ������̫��������ġ�");
                return 1;}
        list = filter_array(users(), (: $1->query("combat_exp")>=1000000 :));
        target = load_object("/d/xueshan/npc/laozu");
        i = target->query("combat_exp")/5;
//        where = "/d/xueshan/xuegu";
                if (me->query_skill("jingmai-xue",1)<170) {
                command("say Ҫ��ָ���㣿�������Ҿ�һ��ǰҪɱһ�ˣ�����˵���ɣ�");
                command("say Ҫ���ҽ����㣬����ȥ���ˣ��ҾͿ����ˡ�"); }
                command("say ��ȥ����ɱ��"+HIR+target->query("name")+HIW+"("+target->query("id")+")"+CYN"�ɡ�");
//                command("say ��ȥ"+HIG+where->query("short")+CYN+"���ҿ���");
                command("sing3");
                target->set_temp("no_zhong",1);
                set("target",target->query("name"));
                set("targetid",target->query("id"));
                me->set_temp("ping_quest",1);
                set("waiting",1);
        return 1;
        }

int accept_object(object me, object ob)
{
        if (!me->query_temp("ping_quest")) {
                command("say ���������ʲô��");
                return 0; }
        if (ob->query("name")==query("target")+"���׼�"
        && ob->query("victim_id")==query("targetid")
        && ob->query("material")=="meat") {
                command("nod");
        if (ob->query_skill("jingmai-xue",1)>=170) {
                command("say �ã��Ҳ��������ġ�");
                ob->add("ping/kill",1);
        } else {
                command("say �ã���ô�ҾͰ��Ȿ�鴫�����ˣ��ú��о��ɡ�");
                message_vision(HIY"ƽһָ����$Nһ���Ƶ��ھ���\n"NOR, me);
                new("/clone/medicine/jingmai/jingmai-book6")->move(me);}
                set("waiting",0);
                return 1; } else {
                command("say ���������ʲô��");
                set("waiting",0);
       return 0; }

}

int ask_me()
{
        object ob;
        ob=this_player();

        if (ob->query("ping/kill")<1) {
            command("grin1 ping");
            command("say �ҿɲ������ˣ�Ҫ�������Ȱ���ɱ������˵��");
            return 1;}
        if ((int)ob->query("eff_qi") == (int)ob->query("max_qi"))
        {
                command("?"+ob->query("id"));
                command("say �����û���ˣ��뵷�ң�\n");
                command("knock "+ob->query("id"));
                return 1;
        }
        else
        {
                message_vision("ƽһָ��ָ΢�����������$N����ʮ�˴���Ѩ��$N�о�������ˡ�\n", ob);
                remove_call_out("recover");
                call_out("recover",2,ob);
                ob->add("ping/kill",-1);
                return 1;
        }
}

int recover(object ob)
{
        ob->set("eff_qi", (int)ob->query("max_qi"));
        ob->set("eff_jing", (int)ob->query("max_jing"));
        message_vision("һ����Ĺ����ȥ�ˣ�����������Ѿ�����Ȭ���ˡ�\n",ob);
        return 1;
}
