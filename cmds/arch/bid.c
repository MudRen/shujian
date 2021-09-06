/**********************************************************************************
//
//      bid.c
//      Created by mychat 31/04/2004
//      �����ҵ�ǩ������� free of use.
//      ��Ȼ����ӭ�޸ġ��Ż��ȡ�
//
//      Email & MSN: codemake@163.com
//      �ļ�λ��/cmds/usr��
// 		
***********************************************************************************/
#include <ansi.h>
#ifndef ROOMLEASE_D
#define ROOMLEASE_D "/adm/daemons/roomleased"
#endif
//#include <roomlease.h>
int main(object me, string arg)
{
//	int    oldbidamount;		
	string bidname,flag;
	int bidamount,mybalance,bidflag;
	string valroomname;
	mapping leasemap;
	
	bidflag=1;
	if( !stringp(arg)) 
		return notify_fail("��Ͷʲô�ꣿ\n");
	if( (sscanf(arg, "%s %d %s", bidname, bidamount,flag)==3)&&(flag=="-t") ){
		bidflag=2;
	}else if( sscanf(arg, "%s %d", bidname, bidamount)==2 );
	else return notify_fail("��Ͷʲô�ꣿ\n");
	
	if (!wizardp(me) && me->query_temp("command_busy"))
                return notify_fail("����æ���ء�\n");
        me->set_temp("command_busy",1);
        call_out("remove_busy", 3, me);
 
	if( !ROOMLEASE_D->query_ifhavebidname(bidname) )	
		return notify_fail(HIY"û���������ҪͶ��\n"NOR );

	leasemap=ROOMLEASE_D->query_amap(bidname);
	
	if( (leasemap["bidtype"]!=1)&&(leasemap["bidtype"]!=2) )
		return notify_fail(HIY"������̻�û����Ͷ��\n"NOR );

	mybalance=me->query("balance");
	//Ͷ��ʱ�õ�silverΪ��λ
	bidamount=bidamount*100;
	
	valroomname=ROOMLEASE_D->get_myregions(leasemap["roomwhere"])+leasemap["originshortname"];

	write( HIY"����д��һ��" + 
		ROOMLEASE_D->money_str(bidamount)+
		"��֧Ʊ����ҪͶ�꡾"+
		valroomname + 
		"��"+
		ROOMLEASE_D->chinese_time(leasemap["leasetime"]) +
		"������Ȩ\n"NOR );
	if(mybalance<bidamount)
		return notify_fail(HIY"������û��ô����\n"NOR);
	call_out("do_bid",3+random(3),me,bidname, bidamount,bidflag);
	return 1;
}

void do_bid(object me,string bidname,int bidamount,int bidflag)
{
	mapping leasemap=ROOMLEASE_D->query_amap(bidname);
	
	me->set_temp("command_busy",1);
        call_out("remove_busy", 3, me);
                
	if(leasemap["leaser"]==me->query("id"))
	{
		tell_object(me,"���ǲ��Ƿ�ɵ�ˣ����Ѿ�����ĵ��ˡ�\n");
		return;
	}
	if(time()<leasemap["bidtime"])
	{
		tell_object(me,HIY"����Ͷ�껹û�п�ʼ�أ����Ժ�������\n"NOR);
		return;
	}
	if(time()>leasemap["bidendtime"])
	{
		tell_object(me,HIY"���ǵ�ǰͶ���Ѿ����������Ժ�������\n"NOR);
		return;
	}
	if(me->query("id")==leasemap["bider"])
	{
		tell_object(me,HIY"��ǰ��߼۾�������ģ���Ǯ���յûţ���Ҫ�Լ��ټӼۣ�\n"NOR);
		return;
	}
	if(leasemap["minirent"]>bidamount)
	{
		tell_object(me,HIY"��������ļ۱���������Χ�۸�\n"NOR);
		return;
	}
	if(leasemap["bidamount"]>bidamount)
	{
		tell_object(me,HIY"��������ļۻ�û��ǰ��߼۸�\n"NOR);
		return;
	}
	if( (leasemap["bidamount"]+leasemap["minirentadd"])>bidamount )
	{
		tell_object(me,sprintf(HIY"���ǼӼ۵���ͷ���Ϊ%d\n",leasemap["minirentadd"]));
		return;
	}
	if(ROOMLEASE_D->new_bid(me, bidname,bidamount,bidflag)) return;
	tell_object(me,"Ͷ��ʧ�ܣ�\n");
}

void remove_busy(object me)
{
        if (me) me->delete_temp("command_busy");
}


int help(object me)
{
  write(@HELP
--------------------------------------------------
ָ���ʽ��bid Ͷ����� Ͷ���� <-t>
--------------------------------------------------
 Ͷ����:��������Ϊ��λ
 -t ���������Ͷ��
 
--------------------------------------------------

HELP
    );
    return 1;
}
