inherit NPC;

#include "/d/zhiye/npc/forbook.c"
#define JADE    "/d/zhiye/obj/othermaterial" //��

int ask_yt()
{
	object me = this_player();
	
	if(is_busy()) return 0;
	
	if(me->query_skill("duanzao",1) < 250
	&& me->query_skill("caikuang",1) < 120
	&& me->query_skill("zhizao",1) < 250
	&& me->query_skill("nongsang",1) < 120 )
	{
		command("say ����������գ�Ҳ���о�ʲô�����������������ⲻ�ǡ���");
		command("regard "+me->query("id"));
		return 1;
	}
	
	if(me->query("worker/hangift"))
	{
		command("say ���ϴβ������ʹ���ô���������ˡ���");
		command("regard "+me->query("id"));
		return 1;		
	}
	
	me->start_busy(100);
	this_object()->start_busy(100);
	
	command("say �����������������£��������������֮������һλ���ˣ������ں�����������в��߲�������ҹ���о��������������ļ���������Ϊ��ȡ��������������������");
	call_out("ytquest_1",1+random(2),me);
	return 1;
}

void ytquest_1(object me)
{
	if(!me) return;
	
	if(me->query("worker/hangift")) return;
	
	if(environment(me)!=environment(this_object())) return;
	
	message_vision(CYN"$N���´�����$n���ۡ�\n",this_object(),me);
	message_vision(CYN"$N٩٩��̸�������֪��ʲô�ǡ������������ԡ��������ϱ����������������ǿ���һ
	�õļ��ܣ��ҵ��˲���֮�꣬�ŷ����������о��ġ�����������������һ�ã���Ϊ�������
	��Ȼ�����ˣ������չ���һ�˵У����������²������к��洦����ǿ��ʤ���ᵳ��ȣ�����
	�������ü����ģ���ɱ�޶ȣ�����ΪӢ�۸�������ʵ�վ���ӹ��һ�����ҵĽ��������ޡ�������
	�ǿ�ϧ���ҽ�������\n"NOR,this_object(),me);
	
	call_out("ytquest_2",1+random(2),me);
}

void ytquest_2(object me)
{
	object obj;
	int level = 1;
		
	if(!me) return;
	
	if(me->query("worker/hangift")) return;
	
	if(environment(me)!=environment(this_object())) return;
	
	if(!random(2)) level+=1;
        if(!random(3)) level+=1;
        if(!random(4)) level+=1;
	if(!random(5)) level+=1;
	
	obj = new(JADE);
        obj->set_level(level);
        
        if(obj)
        {
        	message_vision("$N���䵽���ó�һ��"+obj->name()+"��\n",this_object());
        	message_vision("$N��$nһ��"+obj->name()+NOR"��\n",this_object(),me);
        	command("say �����Ҳûʲô�õĶ����������������ȥ���꣬���������ġ��������������������Ƚ������������ˣ��������ж���ᡣ");
        	message_vision(HIY"$N������ȥ�������������ֻ����λ������������ʲô�������ġ�����������������\n"NOR,this_object() );
        	
        	if(obj->move(me)) me->set("worker/hangift",1);
        	me->interrupt_me();
		me->start_busy(-1);
		me->interrupt_me();		
		this_object()->interrupt_me();
		this_object()->start_busy(-1);
		this_object()->interrupt_me();
        }
}

void create()
{
        set_name("������", ({ "han tiejiang","han", "tie", "jiang","tiejiang" }) );
        set("gender", "����" );
        set("age", 34);
        set("long",
                "����һλ�������Ŵ����������������ش�����������
������ͨ�ò�������ͨ�ˡ�
ֻ��ż��������ɣ��˫Ŀ����¶�����������µ�������\n");
        set("combat_exp", 300);
        set("attitude", "peaceful");
        set("rank_info/respect", "������");
        
        
        set("inquiry", ([
        	"����������": (:ask_yt:),
        ]));
        
        /*
        set("vendor_goods", ({
           (["name":__DIR__"obj/changjian","number":25]),
           (["name":__DIR__"obj/gangjian","number":15]),
           (["name":__DIR__"obj/tiejia","number":22]),
           (["name":"/d/tiezhang/obj/gangzhang","number":10]),
           (["name":__DIR__"obj/gangdao","number":10]),
           (["name":__DIR__"obj/caidao","number":20]),
           (["name":__DIR__"obj/tiechui","number":10]),
           (["name":__DIR__"obj/bishou","number":12])
        }));        
        set("inquiry", ([
                "here" : "�����ǳ���Ψһ�Ĵ������ˣ�ʲô�˶�����������������\n",
                "dazao" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "װ��" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "����" : (: ask_dazao :),
                "װ��" : (: ask_dazao :),  
                "����֮��": (: ask_learn :), 
                "�ɾ�":(: ask_cheng  :),
                "�ɼ�":(: ask_cheng  :),
                "��Ѱ":(: ask_place :),
        ]) );
        */
        set("forg_type","all");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}


void init()
{
	::init();
	add_action("do_taojiao","taojiao");///for tiejiang xx
}
