// ͨ����Ʒ���� mm2.c
// by fengyue 0808
#include <ansi.h>

inherit NPC;

int do_look(string);
int ask_me();
int ask_wuliao();

int ask_cantu();
int ask_daopu();
int ask_ebook();
int ask_tianlong();
int ask_jingpa();
int ask_kongxin();
int ask_pearl();
int ask_putao();
int ask_shuzhi();
int ask_suizhi();
int ask_taijitu();
int ask_wcard();
int ask_yuji();
int ask_zhanshu();
int ask_shenshu();
int ask_fail();


void create()
{
     set_name("�����׺�", ({ "audrey hepburn","girl", "meimei" }) );
      set("title",HIC"���չ���"NOR);
     //set("nickname",HIR"ר ��"NOR);
     set("gender", "Ů��" );
     set("age", 18);
     set("long","����������ɪ�ա��ձ�-³˹�٣�Audrey Kathleen Hepburn-Ruston��;\n"+
                "�������С������\n");
     set("combat_exp", 10000);
     set("attitude", "friendly");
     set("no_get", 1);
     set("per", 30);
     set("inquiry", ([
//                   "sex" :         (: ask_me :),
//                  "make love" :   (: ask_me :),
//                   "QQ" :          (: ask_wuliao :),
//                   "�绰����" :    (: ask_wuliao :),        
//                   "qq" :          (: ask_wuliao :),
//                   "msn" :         (: ask_wuliao :),
//                   "�ֻ�����" :    (: ask_wuliao :),
//                   "name" :        (: ask_wuliao :),

                   "��ҽ�����ͼ" : (: ask_cantu :),
                   "cantu" :        (: ask_cantu :),

                   "�ƾɵ���" :     (: ask_daopu :),
                   "daopu" :        (: ask_daopu :),

                   "��Ӣ֮��" :     (: ask_ebook :),
                   "ebook" :        (: ask_ebook :),

                   "�����˲�" :     (: ask_tianlong :),
                   "tianlong" :     (: ask_tianlong :),

                   "ԧ�����" :     (: ask_jingpa :),
                   "jingpa" :       (: ask_jingpa :),

                   "����ɢ" :       (: ask_kongxin :),
                   "kongxinsan" :   (: ask_kongxin :),

                   "��������" :     (: ask_pearl :),
                   "pearl" :        (: ask_pearl :),

                   "��������" :     (: ask_putao :),
                   "putao" :        (: ask_putao :),

                   "С��֦"  :      (: ask_shuzhi :),
                   "xiaoshuzhi"  :  (: ask_shuzhi :),
 
                   "��ֽƬ" :       (: ask_suizhi :),
                   "suizhi pian" :  (: ask_suizhi :),
 
                   "̫��ͼ" :       (: ask_taijitu :),
                   "taijitu" :      (: ask_taijitu :),
 
                   "��ع����" :   (: ask_wcard :),
                   "guibinka" :     (: ask_wcard :),
 

                   "����" :       (: ask_yuji :),
                   "yujiwan" :      (: ask_yuji :),
 
                   "����ս��" :     (: ask_zhanshu :),
                   "zhanshu" :      (: ask_zhanshu :),
                   
                   "��ӹȫ��" :     (: ask_shenshu :),
                   "shenshu" :      (: ask_shenshu :),
                   	
                   "ʧ��" :     (: ask_fail :),
       
                     ]) );

      setup();
         carry_object(ARMOR_D("changqun"))->wear();
         carry_object(ARMOR_D("flower_shoe"))->wear();
}


void init()
{
	object ob;

	::init();
	add_action("do_look","kiss1");
	add_action("do_look","kick");
	add_action("do_look","flirt");
	add_action("do_look","loveshoe");

	if( interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

int ask_me()
{
	object me;

	me = this_player();
	switch( random(5) ) {
		case 0:
			message("vision", "��ü��" + me->name() +"ŭ���������Ĳ�����ѽ����å�����ȥ��\n", me );
			command("slap " + me->query("id"));
			remove_call_out("kicking");
			call_out("kicking", 1, me);
			break;
		case 1:
			message("vision", "��ü��" + me->name() +"ŭ���������Ĳ�����ѽ����å�����ȥ��\n", me );
			command("kick " + me->query("id"));
			remove_call_out("kicking");
			call_out("kicking", 1, me);
			break;
		case 2:
			command("faint " + me->query("id"));
			break;
		case 3:
			command("rascal " + me->query("id"));
			command("kick2 " + me->query("id"));
			break;
		case 4:
			command("xixi " + me->query("id"));
			command("benger " + me->query("id"));
	}
	return 1;
}

int do_look(string target)
{
	object me;

	me = this_player();
	if (target=="shuang" || target=="shuang er")
	if ((string)me->query("gender") != "Ů��") {
		message("vision", "��ü��" + me->name() +"���������Ĳ�����ѽ��\n", me );
		switch( random(5) ) {
			case 0:
				command("club " + me->query("id"));
				remove_call_out("kicking");
				call_out("kicking", 1, me);
				break;
			case 1:
				command("kick " + me->query("id"));
				remove_call_out("kicking");
				call_out("kicking", 1, me);
				break;
			case 2:
				command("faint " + me->query("id"));
				break;
			case 3:
				command("stare " + me->query("id"));
				break;
			case 4:
				command("rascal " + me->query("id"));
				command("kick2 " + me->query("id"));
		}
	}
	return 0;

}

void kicking(object me)
{
	if (!me || environment(me) != environment()
	|| environment(this_object())->query("short") != "����")
		return;

	me->move("/d/city/guangchangnan");
	message("vision","ֻ�����ء���һ����������" +  me->query("name") +
		"�ӵ�������˳���������һ������ӡ��ƨ������һ��СЬӡ��\n", environment(me), me);
}

int ask_wuliao()
{
     object me;

	me = this_player();
            command("mimi "+me->query("id") ); 
            command("? ");
            command("hmm ");
         return 1;
}

int ask_cantu()
{    
     object me;
     me = this_player();
     command("say ����������Ѿ����Ĺ�"+ chinese_number(me->query("spec/cantu")) +NOR"����ҽ�����ͼ�ˡ�");
     command("say ��Щ��ͼ���Ѿ���(fanyue mjjf cantu)���ö���ˣ���������Ľ���̫���ˣ�û��ָ�㣬������ѧ���ᡣ");
     command("sigh ");
     command("say ��֪��˭��ָ����һ���Ҫ������ѧ���˻������Һò��ã� ");
     command("addoil girl ");
         return 1;
}
int ask_daopu()
{    
     object me;
     me = this_player();
     command("say �������Ѿ�Ū����"+ HIR+chinese_number(me->query("spec/daopu")) +NOR"���ƾɵ����ˡ�");
     command("say ��˵�������¼���Ǵ�˵�����������ĺ��ҵ����أ�");
     command("say ��������Ļ�,�ҿ��Խ���Ŵ󾵸�����ϸ����һ��(bianren pojiu daopu)��������Ҫ���ҳԹ�����˹Ŷ��");
     command("smile ");
         return 1;
}
int ask_ebook()
{    
     object me;
     me = this_player();
     command("say �������Ѿ��õ���"+ HIR+chinese_number(me->query("spec/ebook")) +NOR"����Ӣ֮�顣");
     command("say ��ô��������ô�㾭�鰡��");
     command("push ");
         return 1;
}
int ask_tianlong()
{    
     object me;
     me = this_player();
     command("say �������Ѿ���(read)��"+ HIR+chinese_number(me->query("spec/tianlong")) +NOR"�������˲��ˡ�");
     command("say ���������������������ˣ�");
     command("say ��������˻��ǰ��ϰ���");
     command("sigh ");
         return 1;
}
int ask_jingpa()
{    
     object me;
     me = this_player();
     command("say �������Ѿ��黹�����ð���"+ HIR+chinese_number(me->query("spec/jingpa")) +NOR"��ԧ�������");
     command("say ����û�н���������������");
     command("say ����������̫���ϲ��Ͻ��ң�˵�ұ���");
     command("shout ");
         return 1;
}
int ask_kongxin()
{    
     object me;
     me = this_player();
     command("say �������Ѿ����ù�"+ HIR+chinese_number(me->query("spec/kongxin")) +NOR"�ο���ɢ��");
     command("say ����һ����ң���ڣ��ͻ�ѽ����������ĸɸɾ�����");
     command("say �ⶫ��������Ǵ�˵�е�K�۰�");
     command("fear ");
         return 1;
}
int ask_pearl()
{    
     object me;
     me = this_player();
     command("say �������Ѿ���������(pary)��"+ HIR+chinese_number(me->query("spec/pearl")) +NOR"���ˡ�");
     command("say ��������һ�����������ء�");
     command("say �����һ��Ǿ����Լ�ͦ��ù�ģ���������Щɫ����ɧ���ҡ�");
     command("club ");
         return 1;
}
int ask_putao()
{    
     object me;
     me = this_player();
     command("say �������Ѿ��Թ�"+ HIR+chinese_number(me->query("spec/putao")) +NOR"���������ѡ�");
     command("say ������������ҡ�");
     command("sing ");
         return 1;
}

int ask_shuzhi()
{    
     object me;
     me = this_player();
     command("say �������Ѿ������Ҷ���"+ HIR+chinese_number(me->query("spec/shuzhi")) +NOR"��С��֦�ˡ�");
     command("say �Ҷ�������Ҫ�����Ŷ��");
     command("say ��Բ�ҷ�����ô�򵥵��������Ҳ�ܻ�(hua fangyuan)����Ŷ��");
     command("draw lao ban ");
         return 1;
}

int ask_suizhi()
{    
     object me;
     me = this_player();
     command("say �������Ѿ������Ҷ���"+ HIR+chinese_number(me->query("spec/suizhi")) +NOR"����ֽƬ�ˡ�");
     command("say �����Ƿ�����ȥ����������ʲô��(chakan suizhi pian)��");
     command("say ���������Ž����ؾ�ͼ������");
     command("giggle ");
     command("say �Ž�����ؼ�����ȥ�ˣ����Ŷ����궼û���ˡ�");
     command("laugh ");
         return 1;
}
int ask_taijitu()
{    
     object me;
     me = this_player();
     command("say �������Ѿ���������̫��ͼ�о�(yanjiu taiji tu)"+ HIR+chinese_number(me->query("spec/taijitu")) +NOR"������");
     command("say ���ݵ�ʿ���������̫�����⣬����᲻���Դ���");
     command("say Ҫ����ȥ�������ɡ�");
         return 1;
}
int ask_wcard()
{    
     object me;
     me = this_player();
     command("say �������Ѿ��õ���"+ HIR+chinese_number(me->query("spec/wcard")) +NOR"�Ź������");
     command("say �Ұ�ϴ�裬Ƥ���úã�");
     command("sing ");
     command("say û������(show card)ɶ�أ�����Ϊ�����Լ�����˰���");
     command("wah "+ me->query("id") +" ");

         return 1;
}


int ask_zhanshu()
{    
     object me;
     me = this_player();
     command("say �������Ѿ�����(yuedu)��"+ HIR+chinese_number(me->query("spec/zhanshu")) +NOR"�����ս�顣");
     command("say ���¾Ž����ѵ������������ô�����Ľ���ô�� ");
     command("think ");
     return 1;
}

int ask_yuji()
{    
     object me;
     me = this_player();
     command("say �������Ѿ����ù�"+ HIR+chinese_number(me->query("spec/yuji")) +NOR"�����衣");
     command("say �������Ѿ����ù�"+ HIR+chinese_number(me->query("spec/yuji1")) +NOR"����Ʒ���衣");
     command("say ������ң��������⣬��������....");
     command("blush ");
         return 1;
}

int ask_shenshu()
{    
     object me;
     me = this_player();
     command("say �������Ѿ��Ķ���"+ HIR+chinese_number(me->query("spec/shenshu")) +NOR"�ν�ӹȫ����");
         return 1;
}

int ask_fail()
{    
     object me;
     me = this_player();
     command("say " + HIW + "�������Ͼ�" + NOR + "���Ѿ�ʧ����"+ HIR+chinese_number(me->query("quest/jiuyin1/fail"))+NOR"�Ρ�\n");
     command("say " + HIG + "�������¾�" + NOR + "���Ѿ�ʧ����"+ HIR+chinese_number(me->query("quest/jiuyin2/fail"))+NOR"�Ρ�\n");
     command("say " + HIB + "��Ȫ��" + NOR + "���Ѿ�ʧ����"+ HIR+chinese_number(me->query("quest/ѩɽ�ɺ�/�书/lengquanfail"))+NOR"�Ρ�\n");
     command("say " + HIW + "��󡹦" + NOR + "���Ѿ�ʧ����"+ HIR+chinese_number(me->query("quest/hama/fail"))+NOR"�Ρ�\n");
     command("say " + HIC + "�貨΢��" + NOR + "���Ѿ�ʧ����"+ HIR+chinese_number(me->query("�����˲�/�书/fail"))+NOR"�Ρ�\n");
     command("say " + HIR + "��������" + NOR + "���Ѿ�ʧ����"+ HIR+chinese_number(me->query("quest/pixie/fail"))+NOR"�Ρ�\n");
     command("say " + HIW + "���һ���" + NOR + "���Ѿ�ʧ����"+ HIR+chinese_number(me->query("quest/hubo/fail"))+NOR"�Ρ�\n");
     command("say " + HIR + "��Ѫ��צ" + NOR + "���Ѿ�ʧ����"+ HIR+chinese_number(me->query("quest/ningxue/fail"))+NOR"�Ρ�\n");
     command("say " + HIG + "�𵶺ڽ�" + NOR + "���Ѿ�ʧ����"+ HIR+chinese_number(me->query("quest/jindaoheijian/fail"))+NOR"�Ρ�\n");
     command("say " + HIC + "̫����" + NOR + "���Ѿ�ʧ����"+ HIR+chinese_number(me->query("quest/taixuan/fail"))+NOR"�Ρ�\n");
     command("say " + HIR + "ǧ֩����" + NOR + "���Ѿ�ʧ����"+ HIR+chinese_number(me->query("quest/qianzhu/fail"))+NOR"�Ρ�\n");
     command("say " + HIM + "���ǹ" + NOR + "���Ѿ�ʧ����"+ HIR+chinese_number(me->query("quest/yangjiaqiang/fail"))+NOR"�Ρ�\n");
         return 1;
}
