/*
job_time/
String type 
�ٸ� ؤ�� ��ɽ ѩɽ ��ػ� ���ְ� ��ɽ ���� ����
ע��һЩ�������Ŀ����������
*/
//by spiderii@ty ��Ϸ����Ϊ��������ң���������Ʒ���ּ���
#include <ansi.h>
//#define TT 50         // ÿ50�����������������

#define BOOK    "/clone/gift/book"      //��
#define MIC     "/clone/gift/danwan"    //ҩ
#define MON     "/clone/gift/money"     //Ǯ
#define JADE    "/d/zhiye/obj/othermaterial" //��
#define DAZAO   "/clone/gift/imbue"     //�������

inherit F_DBASE;

public string* Job_Type = ({
"��ɱ","���ϳ�","�漱","����","���߹�","���ְ���","���ֲ˵�","������ֵ",
"�𷨽�ħ","����Ѳ��","��������","�һ���","��Ĺ��Ĺ","��Ĺ�䳲","����",
"Ľ��","����ͭ��","����Ԫ��","���","�ٸ�","ؤ��","��ɽ","ѩɽ","��ػ�",
"���ְ�","��ɽ","Ѳ��","����","����","�䵱","����","�������ս","��������ս",
"����","���־�Ԯ","��������"});

string* super_easy_list = ({"Ѳ��",});

void give_gift(object who,string ob_name,string type,int times);

string* gifts = ({});

void create()
{
        seteuid(getuid());
        set("channel_id", "����������"); 
}

//flag  ��־��
/*
����Ƶ�������ٷֱ�
���� 50 ���ü������50%
*/
void check_count(object who,mixed ob,string type,int flag)
{
        int i,j;
        string ob_name;
        string* myjoblist;
        if(objectp(ob)) ob_name = ob->name();
        else if(stringp(ob)) ob_name = ob;
        
        myjoblist = who->query("myjoblist");
        if(!myjoblist || !arrayp(myjoblist) ) myjoblist= ({});
        
        while(member_array(type,myjoblist)!=-1)
        {
        	string* newmylist = ({});
        	j = 0;        	        	
        	for(i=0;i<sizeof(myjoblist);i++)
        	{
        		if(j)
        		{
        			newmylist += ({myjoblist[i]});
        			continue;
        		}
        		if(myjoblist[i]==type) j = 1;
        	}
        	myjoblist = newmylist;
        }
        myjoblist += ({type});
                        
        who->set("myjoblist",myjoblist);
                
        if (!type || member_array(type,Job_Type)== -1 )       return;
        
        if (!ob_name) return;
                
        if (!intp(i = who->query("job_time/"+type))) return;
        
        if (i <= 0)   return;
        if (i <= who->query("job_last_gift/"+type)) //�Ѿ������Ʒ��
                return;
        if (who->is_robot())	return;
                
        //���ʿ���
        if ( who->is_vip() && who->query("kar") > 25) 
        	j = 100;
        
        else
        {
                if ( who->is_vip() ) j = 80;
                
                else
                {
                        if (who->query("kar") > 25) 
                        	j = 80;
                        else
                                j = 70;
                }
        }
        
        
        //easy job then...
        if( member_array(type,super_easy_list) != -1) flag -= 40;
        
        //grin robot
        if(who->is_robot()) j = j - 60;
                                                                
        j = j + j*flag/100;
        
        i = sizeof(myjoblist)-2;
                
        while(i>0)
        {
        	j = j + j*25/100;
        	i--;
        	//������Խ�� �񽱼���Խ��
        }
                        
        i = who->query("job_time/"+type);
                   
        if (random(100) < j) 
                give_gift(who,ob_name,type,i);
                
        return;                 
}

void ttttttt(string t)
{	
	check_count(previous_object(1),"����",t,0);
}

void give_gift(object who,string ob_name,string type,int times)
{
        //object ob  ob->name()   ob_name
        string msg = "";
        object obj;
        string str = "";
        int i = random(3);
        
        //check_dir();
        //obj = new(DIR+gifts[random(sizeof(gifts))]);
        if (type == "���"){
                obj = new (BOOK);
                str = "��";          
        }
        else if(objectp(obj = WORKER_D->mater_random(who,0,0))) {str = "������Ʒ";}
        else {
        int tt;	
        //int tt = random(2)?(random(2)?who->query("con"):who->query("int")):(random(2)?who->query("str"):who->query("dex"));        
        //tt += random(2)?(random(2)?who->query("con"):who->query("int")):(random(2)?who->query("str"):who->query("dex"));
        //һ�������������ܺ�Ϊ80 �������ȡ���� hehehe
        //tt = tt * 10;
        tt = 100;
        //CHANNEL_D->do_channel( this_object(), "sys",sprintf("������� = %d��",tt));
        if(who->query("job_time/"+type)%tt != 0) return;
        else
        {
        	switch(i) {
                        case 0:         
                                obj = new (BOOK);
                                str = "��";  
                                break;
                        case 1: 
                                obj = new (MIC);
                                if (random(who->query_kar()) > 29) {
                                        obj->set("secret_obj",1);
                                        str = "��Ʒ";
                                }
                                str += "ҩ";     
                                break;
                        case 2:         
                                obj = new (MON);
                                str = "Ǯ"; 
                                break;
                        default:return;
                }
                //10% ���һ�δ������ ������
                if(random(150)<10)
                {
                	int level=1;
                	i = random(2);
                	if(!random(5)) level+=1;
                	if(!random(5)) level+=1;
                	if(!random(5)) level+=1;
                	if(!random(7)) level+=1;
                	destruct(obj);
                	switch(i) {
                		case 0:
                			obj = new(DAZAO);
                			str = "������ʯ";
                			break;
                		case 1:
                			obj = new(JADE);
                			str = "��";
                			obj->set_level(level);
                			break;
                		default:return;              			
                	}
                }
	}
}
	
        if (!objectp(obj))
        {
                CHANNEL_D->do_channel( this_object(), "sys",sprintf("%s����",str));
               // tell_object(who,"��Ʒ���ɳ�����֪ͨ��ʦ��\n"); ��������ҿ��� ����ĺ�
                return;
        }
        obj->set("gift_target",who->query("id"));
        obj->move(who);
        who->set("job_last_gift/"+type,times);
        //give����set last_gift giggle
        switch(type)
                {                
                case "��ɱ":
                	msg = "$N������ȥ·�߳���һ������ؤ��$NͻȻ���������"
                	+ob_name+"\n"+ob_name+
                	"��������ס��$N���֣�˵�����Ҵ���ǧǧ������ΰ��ո�л��λ"
                	+RANK_D->query_respect(who)+
                	"��\n��"+ obj->query("unit") + obj->name()+
                	"�������ϴ���ʱ�����þ��͸�������\n";
                	break;
                case "���ϳ�":
                	msg = ob_name+"Ц����$N�������ɣ����ϰ������߽������������������ؤ����������Ϊ��ؤ�����˲�������֮�£�����ؤ������֮����\n"
                	+RANK_D->query_respect(who)+
                	"����"+obj->query("unit") + obj->name()+"������������ģ������μ�����֮����\n";
                	break;
               	case "�漱":
               		msg = ob_name+"��������ס��$N���֣�˵�����Ҵ���ǧǧ������ΰ��ո�л��λ"
               		+RANK_D->query_respect(who)+
               		"��\n��"+ obj->query("unit") + obj->name()+"�������ϴ���ʱ�����þ��͸�������\n";
               		break;
               	case "����":
			msg = ob_name + "��$N��̾���ѣ���СС��;ͽ�������ô����ʦ�����ҹ�����ʦ���ǣ��ҿ���" + 
			obj->query("unit") + obj->name()+"�������ٺ��ʲ����ˡ�\n";
               		break;
               	case "���߹�":
               		msg = ob_name + "����Ц���е�˵�������˼ҵ��������Ͻл���Ȼ�Ѿ�������ô������Т���Ľл����ˡ�"+
               		"û���ӣ�\n��"+obj->query("unit") + obj->name()+"����һ��С��˼���Ͻл�Ҳ����Ƥһ�������ɣ�\n";
               		break;//npc ho7g
               	case "���ְ���"://npc�̷�ɮ
               		msg = ob_name + "���˿������ϵ��ϼ롣̾����Сʦ����������־�������ޣ�̫ʦ����Ұ���"+
               		obj->query("unit") + obj->name()+"����Ŭ���ĺ�ɮ�ˣ����͸�����ɣ�\n";
               		break;
               	case "���ֲ˵�"://npc Ե�� 
               		msg = ob_name + "��Ц���������Сͺ¿�ɻ���������ϴη�үү�Ҽ���"+
               		obj->query("unit") + obj->name()+"��Ҳ��֪����ʲô�ã��͸�����ɣ�\n";
              		break;
               	case "������ֵ"://npc ��������
               		msg = ob_name + "̾����ʦ������ڿ����»��������˾��尡����"+
               		obj->query("unit") + obj->name()+"������Ҳûʲô���ã�������ʦ�ְɣ�\n";
               		break;
               	case "�𷨽�ħ"://npc xuan-du
               		msg = ob_name + "��һ����ţ�$N������������Ϊɳ�ű��ʡ���"+
               		obj->query("unit") + obj->name()+"���ı�ɷ��ĵĴ������ˡ�\n";
               		break;
               	case "����Ѳ��"://wei yixiao
               		msg = ob_name + "������ס��$N���֣��ػ���ʥ�̣���Ҫ��$N��������֮����\n";
			msg += ob_name + "˵����$NΪ�ҽ̻����������˲�����������"+
			obj->query("unit") + obj->name()+"�ǽ������Ҵ�����ģ��������Ŭ����������̡�\n";
               		break;
               	case "��������"://chang yuchun
               		msg = ob_name + "������ס��$N���֣��ػ���ʥ�̣���Ҫ��$N��������֮����\n";
			msg += ob_name + "˵����$NΪ�ҽ̻����������˲�����������"+
			obj->query("unit") + obj->name()+"�ǽ������Ҵ�����ģ��������Ŭ����������̡�\n";
               		break;
               	case "�һ���"://xiao huang
               		msg = ob_name + "����һЦ������������ֻ˵����������֮ͽ����ȴ���ʵ�ɣ�Ϊ�һ���������ô�����顣�������п��ޡ�\n"+
               		"��"+obj->query("unit") + obj->name()+"�ǵ������ҵģ��Ҿͽ軨�׷𣬸�����ɡ�\n";
               		break;
               	case "��Ĺ��Ĺ"://������
               		msg = ob_name + "���´�����$N���ۡ�\n";
			msg += ob_name + "˵����$N��Ĺ����ɵò�������"+
			obj->query("unit") + obj->name()+"��������ɡ�����ٽ���������ʹ���и��֪����ô����\n";
               		break;
               	case "��Ĺ�䳲"://
               		msg = "����ù������࣬һƨ�����ڵذ��ϡ���Ȼ���õ�����ʲô���һ������Ȼ��"+obj->query("unit") + obj->name()+
               		"��\n����ϲ���񣬼���������";
               		break;
               	case "����"://qiu qianren
               		msg = ob_name + "���͵�������$N�ü��$N�ɵò���Ҳ���������ƺ󱲵�ٮٮ���ˣ���"+
               		obj->query("unit") + obj->name()+"�������Ƶı���ʹ�����ɡ�\n";
               		break;
               	case "Ľ��"://murong fu
               		msg = ob_name + "����$N��̾һ��������Ľ��һ�����˶�����$N�������ڿң����ิ���Ͳ�������������"+
               		obj->query("unit") + obj->name()+"�����ȥ�������պ�����������Ҳ���Ҵ������¡�\n";
               		break;
               	case "����ͭ��"://yu daiyan
               		msg = ob_name + "���������$N��ͷ��\n";
			msg = ob_name + "˵�����㿴��ͭ�����գ�û�й��ͣ�Ҳ�п��ͣ����䵱�������ɣ������ľ������\n"+
			"��"+obj->query("unit") + obj->name()+"�����˶��꣬��һ��������ʲô�ã���������ɡ�\n";
               		break;
               	case "����Ԫ��"://miejue shitai
               		msg = ob_name + "����ĵ���$N��\n";
			msg = ob_name + "˵�����ɵĻ��㲻��������ʹ˽����ˡ���"+
			obj->query("unit") + obj->name()+"���Ҵ���ģ����������ֲ��ã�����ȻҪ�ջأ�\n";
               		break;              	               	
                case "���":
                        msg = ob_name+"����Ц�����������ȻС������Ϊ���׼����һ�����������飬��"+
                        obj->query("unit") + obj->name()+
                        "�ҿ����ʺ���ģ����͸���ɣ�\n";
                        break;
                case "�ٸ�":
                        msg = ob_name+"���˵�ͷ��$NΪ��͢��ЧȮ��֮����ô�ã����Ĳ�����ʵ���ף���"+
                        obj->query("unit") + obj->name()+
                        "�ǳ�͢������ʹͣ���лʥ���ɣ�\n";
                        break;
                case "ؤ��":
                        msg = ob_name+"Ц����$N�������ɣ����ϰ������߽���������������"+
                        "���ؤ����������Ϊ��ؤ�����˲�������֮�£�����ؤ������֮����\n"
                        +RANK_D->query_respect(who)+"����"+obj->query("unit") + obj->name()+
                        "������������ģ������μ�����֮����\n";
                        break;
                case "��ɽ":
                        msg = ob_name+"��ס$N���´������£������������������"+
                        RANK_D->query_respect(who)+
                        "��ɽ��Χ�ŵ��԰�������"+obj->query("unit") + obj->name()+
                        "���һ�ɽ�ɾ������أ����͸����ˣ�\n";
                        break;
                case "ѩɽ":
                        msg = ob_name+"������$N��ͷ������������������Ϊ�ҹ�������ô����Ů��\n���"+
                        obj->name()+
                        "����ǰ������ɽʱ�������ģ�����Ϊ��үү���ģ���ô������͸�������\n";
                        break;
                case "��ػ�":
                        msg = ob_name+"��������ס$N���֣�"+
                        RANK_D->query_respect(who)+
                        "�����Ŵδ�����ӵ���ı������ҷ���־ʿ���Ժ��帴���Ͷ�࿿���ˣ�\n��"
                        + obj->query("unit") + obj->name()+
                        "��ǰ������ܶ������ҽ�����ģ������Ұ������㣡\n";
                        break;
                case "���ְ�":
                        msg = ob_name+"���˿�$N��;������ľ��ݣ��������Σ��ţ���Ϊ�ҳ��ְ������ɱ���ٵ��˵ĸ��֣�\n" + 
                        "������£����ܹ������������ģ���"+
                        obj->query("unit") + obj->name()+
                        "�����İ�֮�����ȥ�ɣ�\n";
                        break;
                case "��ɽ":
                        msg = ob_name+"��������ס��$N���֣�����ͳһ�Ĵ��£������������࣬�ѵ�" +
                        RANK_D->query_respect(who)+
                        "������������ô���ģ�Ϊ����������֮�±�����\n��" + 
                        obj->query("unit") + obj->name()+"������ɽ��ǰ���������ȥ�ɣ�\n";
                        break;
                case "Ѳ��":
                        msg = ob_name+"��������ס��$N���֣���λС�ֵܣ��ѵ�" +
                        RANK_D->query_respect(who)+
                        "��Ϊ�Ҵ���Ѳ�ǣ�\n��"+ obj->query("unit") + obj->name() +
                        "��Ҳ�������ã������ȥ�ɣ�\n";
                        break;
                case "����":
                	    msg = ob_name+"���ż�����ϸ������ֻ����ɫԽ�����أ��ıϳ�̾һ����" +
                	    "����ż�����������Ҫ���⿪�˶�����������ͷ�����š�\n�ѵ�$Nǧ�����Ϊ����������"
                	    + obj->query("unit") + obj->name()+
                	    "���ղض��꣬���ھ��͸���ɣ�������ڣ�\n";
                        break;
                case "����":
                        msg = ob_name+"���ź��룬�����۾���������������������������$N��ͷ��\n" + 
                        "С�����Դ����ǻ��磬Ϊ�����Ҹ蹦�̵£��߾����ܣ���֪������Ҳ���������ɣ�\n��"+
                        obj->query("unit") + obj->name()+"�����������޺���Բ�������ã�" + 
                        "������ô�������һ��ľ��͸�������\n";
                        break;
                case "�䵱":
                        if (str == "ҩ"||str == "��Ʒҩ")
                                msg = ob_name+"���˵�ͷ��$NΪ���䵱��������ô���£�û�й���Ҳ�п��ͣ�\n" + 
                                "��"+ obj->query("unit") + obj->name()+
                                "�����䵱���������õļ�Ʒ���������ȥ�����ú�����Ч��\n";
                        else
                                msg = ob_name+"���˵�ͷ��"+who->query("name")+
                                "��Ϊ���䵱��������ô���£���ʵ���ף���" +
                                obj->query("unit") + obj->name() + 
                                "������ʦ�������˸��ҵģ�\n���͸��㣬����ٳ߸�ͷ����һ���������棡\n";
                        break;
                case "����":
                        msg = ob_name+"�ܵ�Ƥ��������$N��ͷ��˵��������������" +
                        "��Ϊ��������ô���£���Ҳ��������㣡\n��"+ obj->query("unit") + 
                        obj->name()+"����ǰ��������ԭ���ã�������ô���ľ������͸�������\n";
                        break;
                case "�������ս":
                        msg = ob_name+"��������ס��$N���֣�˵��������������" + 
                        RANK_D->query_respect(who) + 
                        "Ϊ�Ҵ����������ô��������Ҳ��������㣡\n��" + 
                        obj->query("unit") + obj->name() + 
                        "�ǿ���ү���ҵģ�������ô�������͸�������\n";
                        break;
                case "��������ս":
                        msg = ob_name + "��������ס��$N���֣�˵��������������" + 
                        RANK_D->query_respect(who) + 
                        "Ϊ�Һ����������ô��������Ҳ��������㣡\n��" + 
                        obj->query("unit") + obj->name() + 
                        "�Ǻ�����͸��ҵģ�������ô�������͸�������\n";
                        break;
                case "����":
                        msg = ob_name + "��������ס��$N���֣�˵��������������" + 
                        RANK_D->query_respect(who)+"Ϊ�Ҹ����ھ�Ѻ������ô����ڣ���Ҳ��������㣡\n��" +
                        obj->query("unit") + obj->name() + 
                        "���Ҷ�����أ�������ô�������͸�������\n";
                        break;
                case "���־�Ԯ":
                	msg = ob_name+"��������ס��$N���֣�˵��������ƽ��ɽ��Χ��" + 
                	RANK_D->query_respect(who) + "�Ĺ�������\n��" +
                	obj->query("unit") + obj->name() + 
                	"����ʼ�������ҵı����������Լ̳�����\n"; 
                	break;
                case "��������":                	
                	msg = ob_name+"��Ȼ������ʲô�������е���������������\n"+
                	ob_name+"˵������"+
                	ob_name+"����"+RANK_D->query_respect(who)+"����ȫ�����Իر������ﻹ��һ"+
                	obj->query("unit") + obj->name() + 
                	"����ȥ����ʦ���𴦻�����ʱ�����ģ���Ҳûʲô�ã�������ɡ���";
                default:
        }
        message_vision(msg+ob_name+"��$Nһ"+ obj->query("unit")+obj->name()+"��\n",who);

        if (type != "���")
        	CHANNEL_D->do_channel( this_object(), "rumor",sprintf("��˵%s��%s�������һ%s��",who->query("name"),ob_name, obj->query("unit") + obj->name()));
        
        if (type != "���")
        log_file("job/PRIZE",
                sprintf("%s��%d��%s������%s������", 
                who->name(1)+"("+getuid(who)+")",
                who->query("job_time/"+type),
                type,str
                ),who
                );
}
