inherit NPC;
inherit F_VENDOR;

string ask_dan_1();
string ask_dan_2();

void create()
{
        set_name("��ͯ", ({ "dao tong"}));
        set("long", 
                "����һ���䵱��ר�Ÿ���������ҩ��С��ͯ��\n");
        set("gender", "����");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("dex", 25);
        
        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);
        set("combat_exp", 2000);
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);
        set("inquiry", ([
                "ҩ��" : "����Ҫ֪��ʲôҩ������",
                "��ҩ" : "����Ҫ֪��ʲôҩ������",
              "��ҩ" : (: ask_dan_1 :),
              "�ٲݵ�" : (: ask_dan_2 :),
                 "cht" : "�����䵱�ɵ�����ʦ�����㶼��֪������",
              "������" : "�����䵱�ɵ�����ʦ�����㶼��֪������",
            "�����˵�" : "�����˵�����ʹ����Ѫ��ӯ��������ʢ��",
              "������" : "��˵������ʹ��������õ�����������",
          "�׻�������" : "����Ǿ�������ҩ����һ�㲻���׵õ���ҩ�����㻹ȥ���ʱ��˰ɡ�",
          "��¶����ɢ" : "��¶����ɢ��Ľ���ɵ��鵤��ҩ��������ʹ�����;����õ�һ����ߣ�",
          "�Ż���¶��" : "�Ż���¶�����һ�������ҩ�����˿���ʹ����Ѫ��ӯ��",
          "��ת������" : "��˵�����ɵ�ʥҩ�����ƺ��þ�û�˳Ե��ˡ�",
          "�����赨ɢ" : "��Ҳ��һ�����˵���ҩ������֮���˵�¹ܴ���С��ȫ�������κã�",
          "����۾���" : "��˵�����ɵ�ʥҩ��Ч������Ⱦ�ת�������ʤһ����Ҵ���Ҳû������",
          "��ת���굤" : "������ʦ�����¡�ɣ�",
              "�󻹵�" : "��ȥ���������Ұɣ�����˵�������ֵ��ӳ���Ҳ�״",
              "С����" : "�㻹��ȥ�������µĺ����Ǵ���һ�°ɣ�",
        ]));

        create_family("�䵱��", 5, "����");

        set("vendor_goods", ({
             ([ "name": MEDICINE_D("drug/baotai"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/shouwu"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/jugeng"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/chuanbei"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/shengdi"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/mugua"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/zanghonghua"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/tianqi"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/shadan"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/xionghuang"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/heye"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/xuelianzi"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/hugu"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/fuling"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/baizhi"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/renshen"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/chantui"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/niuhuang"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/huangqi"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/gouji"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/chaihu"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/zhuye"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/hua"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/danggui"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/baiwei"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/fangfeng"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/huoxiang"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/sangye"),"number" :10 ]),
             ([ "name": MEDICINE_D("drug/tianhua"),"number" :10 ]),
        }));

        setup();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}

string ask_dan_1()
{
        object ob = this_player();

        if(random(ob->query("kar",1)) > 20 && random(10) > 2 ){
            command("whisper " + ob->query("id") + " �ðɣ��Ҹ����㣬���ǧ��Ҫ���߱��˰������򡭡�");
            command("whisper " + ob->query("id") + " ���ҩ�������ݴ�����һ�����������ˮ���ƶ��ɵģ�");
            return "����������֪���˰ɡ�";
        }
        return "�Բ�������ʦ�����Ұ�ҩ��й¶��ȥ��������С���ѱ���";
}

string ask_dan_2()
{
        object ob = this_player();

        if(random(ob->query("kar",1)) > 20 && random(10) > 2){
           command("whisper " + ob->query("id")+ " �ðɣ��Ҹ����㣬���ǧ��Ҫ���߱��˰������򡭡�");
           command("whisper " + ob->query("id")+ " ��ٲݵ��������ݲغ컨��һ�ݷ��������ˮ���ƶ��ɵġ�");
           return "����������֪���˰ɡ�";
        }
        return "�Բ�������ʦ�����Ұ�ҩ��й¶��ȥ��������С���ѱ���";
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
