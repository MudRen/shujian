// mao.c
// Creator : Numa@Sj 00-5-28 12:02

#include <ansi.h>
inherit NPC;

string do_give_book();
string do_lingwu_dmd();

void create()
{
        set_name("éʮ��", ({ "mao shiba", "mao" }));
        set("gender", "����");
        set("age", 32);
        set("long", "һ����״󺺣�ͷ�ϰ��˰ײ���\n");
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 30);
        set("int", 20);
        set("con", 30);
        set("dex", 26);
        set("startroom", "/d/city/dongxiangfang");

        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("combat_exp", 200000);
        set("inquiry", ([
                "name" : "����é��é�ݵ�é������ë��֮�棬���е�ʮ�ˡ�éʮ�˱������ˡ�",
                "rumors" : "���Ƕ��Ǵ󺺰��գ�������ɽȴ������ռ�ˣ�����һ�գ�Ҫ������ɱ�øɸɾ�����",
                "�ؼ�" : (: do_give_book :),
                "�廢���ŵ�" : (: do_lingwu_dmd :),
        ]));

        set_skill("force", 100);
        set_skill("huntian-qigong",100);
        set_skill("dodge", 120);
        set_skill("xiaoyaoyou",120);
        set_skill("blade",120);
        set_skill("wuhu-duanmendao",120);
        set_skill("parry", 100);
        set_skill("taizu-quan", 100);
        set_skill("cuff",100);
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "wuhu-duanmendao");
        map_skill("blade", "wuhu-duanmendao");
        map_skill("cuff", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");
        setup();

        carry_object(__DIR__"obj/cloth")->wear();
        carry_object(__DIR__"obj/blade")->wield();
}

string do_give_book()
{

        object me = this_player();
        object ob;

        if (!me->query("mao18/pass"))
                return "�ؼ���ʲô�ؼ�����֪����";
        if (present("wuhuduanmendao miji",me))
                return "Ү�������ϲ�����һ����";
        ob = new("/d/city/obj/whdmd-book");
        if (!ob)
                return "�ؼ��Ҹ�Ū���ˣ��㻹�Ǹ�����ʦ����ɣ�";
        ob->move(me);
        ob->set_temp("mao18/book",me->query("id"));
        message_vision("éʮ�˵ݸ�$Nһ���ؼ���\n", me, );
        return "�Ȿ�ؼ�����ȥ�ú��ж������������Ź���ú÷�����";
}

string do_lingwu_dmd()
{
        object me = this_player();
        int i;

        if (!me->query("mao18/pass"))
                return "�廢���ŵ������ҵľ�ѧ�������ʲô��";
        if (me->query("mao18/pass2"))
                return "�ҵ�ȫ����ѧ���Ѿ��̸�����ѽ��";
        i = me->query_skill("wuhu-duanmendao",1);
        if (i != 150)
                return "�㲻ȥ�ú��ж��ؼ����ܵ���������ʲô��";
        me->set("mao18/pass2",1);
        tell_object(me, CYN"éʮ�˶���˵�������������廢���ŵ���ѧ����һ������������������ʽ����������һ���湦��\n�����ھͰ����֡��ͻ���ɽ���������㡣\n"NOR);
        tell_object(me, HIY"������éʮ�˵Ļ������л�Ȼ���ʣ��廢���ŵ������������һ�㣡\n"NOR);
        tell_room(environment(me), "éʮ����"+me->name()+"�������ֹ�����˵��Щ����\n", ({me}));
        return "���ȥ�ӽ������ɣ�";
}
