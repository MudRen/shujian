/*
���ļ�����������JOB�Ľ�����ԭ�л����ϵı������ƣ�100��ʾ����
LinuX@SJ 04/03/01
*/

// Ciwei@SJ ����ղ��ϡ��������١���ɱ���� ��������Ľ���
// ��GBLU_JOB_MUL XXQJ_JOB_MUL ʵ��Ӱ�쵽������ ����ղ��ϡ��������١���ɱ���� ���и漱
// �ֱ����50% 7,7,2004-2:30

/*
һЩС˵���� 
gifted ��ָ��job�Ѿ�������GIFTD��job������
nogiftdָû�м���GIFTD������
���ʲô��û��˵��û�����κδ���
joblist��������Ǹ�job��job_time/xxxx�е�xxxx����
�����·�����漰�����ļ���·����
���ڽ����²���
*/
#ifndef _JOBMUL_H_
#define _JOBMUL_H_

#define VIP_MUL		  150	//�����Һ���ͨ��ҵ������ٶȿ���
#define VIP_LINGWU_MUL	  150   //�����Һ���ͨ��ҵ������ٶȿ���
#define VIP_LEARN_MUL	  150   //�����Һ���ͨ��ҵ�ѧϰ�ٶȿ���
#define VIP_STUDY_MUL	  150   //�����Һ���ͨ��ҵĶ����ٶȿ���
#define ROBOT_MUL	50	 //ROBOT��ҵĳɳ��ٶ�

#define SL_LINGWU_MUL	  100   //��������
#define MR_LINGWU_MUL	  100   //Ľ������
#define LEARN_MUL	  100   //ѧϰ�ٶ�
#define STUDY_MUL	  100   //�����ٶ�

/*��������(����)*/
#define WG_JOB_MUL        120	//������� gifted joblist:��� /d/wuguan/npc/dizi1.c
#define XC_JOB_MUL        120	//Ѳ������ gifted joblist:����	Ѳ��			   /d/dali/npc/zhudanchen.c			
#define SX_JOB_MUL        50	//�������� gifted joblist:����  ����               /d/dali/job/dali_letter.c
#define GBWU_JOB_MUL      60	//ؤ���ⳤ��ɱ������            gifted    joblist:ؤ��                     /adm/daemons/taskd.c
																									// /kungfu/gaibang/wu.c
#define GBLU_JOB_MUL      120	//ؤ��³���ϱ�Ч��������           gifted  joblist:�漱           // �漱: /kungfu/class/gaibang/obj/gaoji-wenshu.c
							///kungfu/class/gaibang/gb_lujob.h
																  // gifted		joblist:��Ч���� ���ϳ�			// ���ϳ���/kungfu/class/gaibang/lu.c	
																  // gifted	joblist:��Ч���� ��ɱ		// ��ɱ��/d/gb/npc/yuanshuai.c
#define SS_JOB_MUL        60	//��ɽ����			gifted					/adm/daemons/taskd.c    taskd ͳһ���㣬 ʵ�ʱ仯ΪGBWU_JOB_MUL
																				// /kungfu/class/songshan/zuo.c zuo.h
#define WD_JOB_MUL        80	//�䵱���� gifted    joblist:�䵱 �䵱����                           /kungfu/class/wudang/song.c
#define LAOZU_JOB_MUL     80	//ѩɽ���� gifted    joblist:ѩɽ                            
#define XX_JOB_MUL        80	//�������� gifted    joblist:����               /adm/daemons/taskd.c     taskd ͳһ���㣬 ʵ�ʱ仯ΪGBWU_JOB_MUL 
																							// /d/xingxiu/npc/ding.c
#define XXQJ_JOB_MUL 	  100	//������������           nogifted  joblist:����                              /d/xingxiu/npc/anran.c
#define HS_JOB_MUL        50   //��ɽ����               gifted    joblist:��ɽ                  /d/huashan/npc/yuebuqun.c


#define TDH_JOB_MUL       55	//��ػ�����  /clone/npc/tdh/man1.h
#define CHANGLE_JOB_MUL	  100	//���ְ�����  /d/changle/npc/bei.c
#define HZ_JOB_MUL        40	//��ս���� ����Ѿ���ȫ�Զ�robot���ٶȿ��Դﵽ8K/Сʱ /d/sld/seawar/seaward.c
#define SWZB_JOB_MUL      100	//ʨ���������� �����ڼ䣬�ȵ��Ϳ���

/*����JOB*/
#define ZHUANJI_JOB_MUL			100   //����JOB /clone/npc/zha
#define LOSELETTER_JOB_MUL		100   //��ʧ����JOB /clone/gift/loseletter.c
/*�����������ǲ�pot��*/
#define ZM_JOB_MUL        100	//��������            gifted    joblist:����                                    /d/city/kedian/zhao.c
#define H7G_JOB_MUL       70	//���߹�����          nogifted   joblist:���߹�                         /kungfu/class/gaibang/h7g.c
/*������job��ʱ�����*/

/*��������(�Ŷ�)*/
#define HUBIAO_JOB_MUL    120   //��������            gifted   joblist:����            /d/fuzhou/hubiao/obj/cart.c /d/fuzhou/hubiao/hubiao.h
#define JIUYUAN_JOB_MUL   100	//���־�Ԯ����        gifted     joblist:����                                   /kungfu/class/shaolin/fang-zheng.c
#define SMY_JOB_MUL       100	//Ħ���¿�������      gifted   joblist:��Ч���� ��Ħ��                              /kungfu/condition/smy_job.c

/*��������*/

/*
sld job
///d/sld/npc/obj/suomp.c -> /tmp/ciwei/job/suomp.c �ɹ���
///d/sld/npc/obj/zhaohp.c -> /tmp/ciwei/job/zhaohp.c �ɹ���
*/

#define SL_AOZHOU_JOB_MUL 	70	//���ְ�������        nogifted    joblist:���� ���ְ���                               /d/shaolin/xjchu.c
#define SL_CAIDI_JOB_MUL  	70	//���ֲ˵�����        nogifted    joblist:���ֲ˵�                               /d/shaolin/obj/tie-tong.c
#define SL_LUNZHI_JOB_MUL       70	//������ֵ����    nogifted    joblist:���� ������ֵ                              /kungfu/class/shaolin/hui-xiu.c
#define SL_MONK_JOB_MUL      	70	//������ɮ������  nogifted    joblist:����  �޺���                             /kungfu/class/shaolin/wuseng.h
                                                                                                         // job ����ͳ���� /kungfu/class/shaolin/xuan-can.h
#define SL_DUSHI_JOB_MUL      	70	//���ֶ����������� nogifted   joblist:�𷨽�ħ                               /kungfu/class/shaolin/xuan-du.h
/*���job��ʱ�����*/
#define MJ_XUNLUO_JOB_MUL       70	//����Ѳ������     nogifted   joblist:���� ����Ѳ��                               /kungfu/class/mingjiao/wei.c
#define MJ_SHOUWEI_JOB_MUL      70//������������     nogifted   joblist:��������                              /kungfu/class/mingjiao/chang.c
#define THD_SHOUMU_JOB_MUL      70	//�һ�����Ĺ����   nogifted   joblist:�һ���                               /d/thd/npc/thdjob.h
#define GM_HUMU_JOB_MUL     	70	//��Ĺ��Ĺ����     nogifted   joblist:��Ĺ��Ĺ                               /d/gumu/fang.c
#define GM_FENGCHAO_JOB_MUL     70	//��Ĺ�䳲����     nogifted   joblist:��Ĺ�䳲                               /d/gumu/yaofang.c
#define TZ_JOB_MUL 	  	70	//���ư�����               nogifted   joblist:����                               /d/tiezhang/npc/tz_job1.c
#define MR_TOUXUE_JOB_MUL       70	//Ľ��͵ѧ����     nogifted   joblist:Ľ��                               /d/mr/npc/murong-fu.c
#define EM_YUANBING_JOB_MUL 	70	//����Ԫ������     nogifted   joblist:����Ԫ��                               /kungfu/condition/em_job1.c
#define WD_SHOUDING_JOB_MUL     70	//�䵱�ض�����     nogifted   joblist:����ͭ��                               /d/wudang/ldfang.c

/*ְҵϵͳ*/
#define ZY_CAIKUANG_MUL         70     ///�ɿ�            nogifted   no joblist  /d/zhiye/caikuang-chang.h
#define ZY_CAIKUANG_JOB_MUL     70     //�ɿ�job          nogigted   no joblist  /d/zhiye/npc/tiejiang.c
#define ZY_ZHUJIAN_JOB_MUL      70     //�ͽ�job          nogifted   no joblist  /d/zhiye/npc/zhujian-shi.c
#define ZY_ZHUJIAN_MUL          70     //                 nogifted   no joblist  /d/zhiye/obj/zhujianlu.c
#define ZY_NONGSANG_MUL         70     //ũɣ             nogifted   no joblist  /d/zhiye/nongtian.h   sanglin.h
#define ZY_ZHIZAO_JOB_MUL       70     //zhizaojob        nogited    no joblist  /d/zhiye/npc/caifeng.c
#define ZY_ZHIZAO_MUL           70     //zhizao           nogifted   no joblist  /d/zhiye/obj/caifengzhuo.c

#define JOB_GIFT_MUL ([ \
	"����"               :70,/**/\
	"ѩɽ"               :100,/**/\
	"���ְ�"             :100,/**/\
	"���"               :120,/**/\
	"Ѳ��"               :100,/**/\
	"����"               :50,/**/\
	"��ɽ"               :60,/**/\
	"ؤ��"               :60,/**/\
	"����"               :70,/**/\
	"�漱"               :120,/**/\
	"���ϳ�"             :100,/**/\
	"��ɱ"               :100,/**/\
	"�䵱"               :70,/**/\
	"��ɽ"               :50,/**/\
	"��ػ�"             :55,/**/\
	"��������ս"         :40,/**/\
	"�������ս"         :40,/**/\
	"����"               :100,/**/\
	"��ʧ����"           :100,/**/\
	"����"               :130,/**/\
	"���־�Ԯ"           :70,/**/\
	"��Ħ��"             :100,/**/\
	"��������"           :70,/**/\
	"�����л�"           :70,/**/\
	"���ְ���"           :70,/**/\
	"���ֲ˵�"           :70,/**/\
	"������ֵ"           :70,/**/\
	"���ֽ̺���"         :70,/**/\
	"����Ѳ��"           :70,/**/\
	"��������"           :70,/**/\
	"�һ���"             :70,/**/\
	"��Ĺ��Ĺ"           :70,/**/\
	"��Ĺ�䳲"           :70,/**/\
	"����"               :70,/**/\
	"Ľ��"               :70,/**/\
	"����Ԫ��"           :70,/**/\
	"����ͭ��"           :70,/**/\
	"�ɿ�"               :70,/**/\
	"�ɿ�����"           :70,/**/\
	"�ͽ�����"           :70,/**/\
	"����"               :70,/**/\
	"ũɣ"               :70,/**/\
	"֯������"           :70,/**/\
	"֯��"               :70,/**/\
	"��������"           :70,/**/\
	"��ɽ����"           :70,/**/\
	"��ɽ��ʯ"           :70,/**/\
])

#endif
